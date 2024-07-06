#include "telemetryreader.h"

TelemetryReader::TelemetryReader(QObject *parent) : QObject(parent)
{
  this->filenameindex = 0;
  this->deletefile = true;
  this->data = new Telemetry_Data(this);

}

void TelemetryReader::on_sessionstringupdate(SessionString *s){
  QString filename = s->telemetryoptions->get_TelemetryDiskFile();
  if(filename.length() > 4){
      filename = filename.replace(1,1, ":");

  bool nieuw = true;
  for(int i = 0; i < this->filenames.count(); i++){
      if(this->filenames[i] == filename){
          nieuw = false;
          break;
        }
    }
  if(nieuw){
      this->filenames.push_back(filename);
      qDebug() << "NEW TELEMETRY FILE " << filename;
    }
    }
}

bool TelemetryReader::fileExists(QString path) {
    QFileInfo check_file(path);
    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {

        return true;
    } else {
        return false;
    }
}

void TelemetryReader::process(){
  this->exit = true;
  QEventLoop l_event;
  while(this->exit == false){
      this->filenameindex++;
      if(this->filenameindex >= this->filenames.count()){
          this->filenameindex = 0;
        }
      if(this->filenames.count() != 0){
          if(this->fileExists(this->filenames[filenameindex])){
              irsdkDiskClient *dc = new irsdkDiskClient();
              if(dc->openFile(this->filenames[filenameindex].toUtf8())){
                  SessionString *sessionstring = new SessionString(this);
                  sessionstring->set_sessionstring(dc->getSessionStr());
                  sessionstring->singleshot();
                  QString output = "<html><body><table>";
                  QString output1 = "";
                  output+="<tr><th>NAME</th><th>DESCRIPTION</th><th>TYPE</th><th>UNIT</th><th>count</th></tr>";
                   QString types[6] = {"irsdk_char", "irsdk_bool", "irsdk_int", "irsdk_bitField", "irsdk_float", "irsdk_double"};
                  for(int i = 0; i < dc->m_header.numVars; i++){
                      irsdk_varHeader pVar = dc->m_varHeaders[i];

                    //  output1+="this->"+ QString(pVar.name) +" = new ir_tel_var(this, \"" + QString(pVar.name) + "\");\n";
                    //  output1+="this->all_vars.push_back(this->"+ QString(pVar.name) +");\n";
                      //output1+="ir_tel_var *"+ QString(pVar.name) +";\n";
                      output1+="delete this->"+ QString(pVar.name) +";\n";
                      output+="<tr><td> "+ QString(pVar.name) + "</td><td>" + pVar.desc +"</td><td>"+ QString::number(pVar.type) + "//"+ types[pVar.type] +"</td><td>"+ pVar.unit +"</td><td>"+ QString::number(pVar.count) +"</td></tr>";

                      for(int y = 0; y < this->data->all_vars.count(); y++){
                          if(this->data->all_vars[y]->name == QString(pVar.name)){
                             this->data->all_vars[y]->set_var_hdr(&pVar);

                             break;
}

                        }

                    }
                  output+="</table></html>";
                  QFile htmlfile(QCoreApplication::applicationDirPath() +"/all_telemetry_vars.html");
                  if (!htmlfile.open(QIODevice::Truncate | QIODevice::WriteOnly)) {
                      qDebug("Basically, now we lost content of a file");
                    //  return;
                  }
                //  QByteArray xml = doc.toByteArray();
                  htmlfile.write(output.toUtf8());
                  htmlfile.close();
                  emit this->output1(output1);

                  for(int i = 0; i < this->data->all_vars.count(); i++){
                      this->data->all_vars[i]->idx_addres = dc->getVarIdx(this->data->all_vars[i]->name.toUtf8());
                    }


                  Telemetry_Save_Data *save = new Telemetry_Save_Data(this);
                  save->userid = sessionstring->driverinfo->get_DriverUserID().toInt();
                  save->sessionid = sessionstring->weekendinfo->get_SessionID().toInt();
                  save->subsessionid = sessionstring->weekendinfo->get_SubSessionID().toInt();
                  save->TrackID = sessionstring->weekendinfo->get_TrackID().toInt();
                  DriverInfo_Drivers *dr = sessionstring->driverinfo->get_driver(sessionstring->driverinfo->get_DriverCarIdx().toInt());
                  save->CarID = dr->get_CarID().toInt();

                  int SessionNo = -1;
                  QString SessionType = "NotDefined";
                  int lap = -1;
                  Telemetry_Save_Data_Lap *l = nullptr;

                  float lf = 100.0f;
                  float rf = 100.0f;
                  float lr = 100.0f;
                  float rr = 100.0f;
                  while(dc->getNextData()){
                      for(int i = 0; i < this->data->all_vars.count(); i++){
                          switch(this->data->all_vars[i]->type){
                            case irsdk_VarType::irsdk_int:
                              {
                                this->data->all_vars[i]->value[0] = dc->getVarInt(this->data->all_vars[i]->idx_addres);
                              }
                              break;
                            case irsdk_VarType::irsdk_float:
                              {
                                this->data->all_vars[i]->value[0] = dc->getVarFloat(this->data->all_vars[i]->idx_addres);
                              }
                              break;
                            case irsdk_VarType::irsdk_double:
                              {
                                 this->data->all_vars[i]->value[0] = dc->getVarDouble(this->data->all_vars[i]->idx_addres);
                              }
                              break;
                            }
                         // this->data->all_vars[i]->set_raw_data(dc->m_varBuf);
                        }
                      if(SessionNo != this->data->SessionNum->value[0].toInt()){
                          if(SessionNo != -1){
                              qDebug() << "TELEMETRY OVER SESSION";
                              SessionNo = this->data->SessionNum->value[0].toInt();
                              SessionType = sessionstring->sessioninfo->Get_Session(SessionNo)->get_SessionType();
                              save->SessionNo = SessionNo;
                              save->SessionType = SessionType;
                            }else{
                              SessionNo = this->data->SessionNum->value[0].toInt();
                              SessionType = sessionstring->sessioninfo->Get_Session(SessionNo)->get_SessionType();
                              save->SessionNo = SessionNo;
                              save->SessionType = SessionType;
                            }
                        }
                      if(lap != this->data->Lap->value[0].toInt()){
                          if(l != nullptr){
                              save->Laps.push_back(l);
                            }
                          l = new Telemetry_Save_Data_Lap(this);
                          lap = this->data->Lap->value[0].toInt();
                        }

                      if(l != nullptr){
                          int distpct = this->data->LapDistPct->value[0].toFloat() * 1000;
                          if((distpct > 0) && (distpct < l->Data.count() -1)){
                          Telemetry_Save_Data_Lap_PCT *p = l->Data[distpct];
                          p->isset = true;
                          p->lap = this->data->Lap->value[0].toInt();
                          p->lat = this->data->Lat->value[0].toDouble();
                          p->lon = this->data->Lon->value[0].toDouble();
                          p->alt  = this->data->Alt->value[0].toDouble();
                          p->TrackTemp = this->data->TrackTemp->value[0].toFloat();
                          p->TrackSurface = this->data->PlayerTrackSurface->value[0].toInt();
                          p->throttle = this->data->Throttle->value[0].toFloat();
                          p->brake = this->data->Brake->value[0].toFloat();
                          p->fuel  = this->data->FuelLevel->value[0].toFloat();
                          p->RRSpeed  = this->data->RRspeed->value[0].toFloat();
                          p->RRPressure  = this->data->RRpressure->value[0].toFloat();
                          p->RRColdPressure  = this->data->RRcoldPressure->value[0].toFloat();
                          p->RRTempL  = this->data->RRtempL->value[0].toFloat();
                          p->RRTempM  = this->data->RRtempM->value[0].toFloat();
                          p->RRTempR  = this->data->RRtempR->value[0].toFloat();
                          p->RRTempCL  = this->data->RRtempCL->value[0].toFloat();
                          p->RRTempCM  = this->data->RRtempCM->value[0].toFloat();
                          p->RRTempCR  = this->data->RRtempCR->value[0].toFloat();
                          p->RRWearL  = this->data->RRwearL->value[0].toFloat();
                          p->RRWearM  =this->data->RRwearM->value[0].toFloat();
                          p->RRWearR  = this->data->RRwearR->value[0].toFloat();
                          p->LRSpeed  = this->data->LRspeed->value[0].toFloat();
                          p->LRPressure  = this->data->LRpressure->value[0].toFloat();
                          p->LRColdPressure  = this->data->LRcoldPressure->value[0].toFloat();
                          p->LRTempL  = this->data->LRtempL->value[0].toFloat();
                          p->LRTempM  = this->data->LRtempM->value[0].toFloat();
                          p->LRTempR  = this->data->LRtempR->value[0].toFloat();
                          p->LRTempCL  = this->data->LRtempCL->value[0].toFloat();
                          p->LRTempCM  =this->data->LRtempCM->value[0].toFloat();
                          p->LRTempCR  = this->data->LRtempCR->value[0].toFloat();
                          p->LRWearL  = this->data->LRwearL->value[0].toFloat();
                          p->LRWearM  = this->data->LRwearM->value[0].toFloat();
                          p->LRWearR  = this->data->LRwearR->value[0].toFloat();
                          p->RFSpeed  = this->data->RFspeed->value[0].toFloat();
                          p->RFPressure  = this->data->RFpressure->value[0].toFloat();
                          p->RFColdPressure  = this->data->RFcoldPressure->value[0].toFloat();
                          p->RFTempL  = this->data->RFtempL->value[0].toFloat();
                          p->RFTempM  = this->data->RFtempM->value[0].toFloat();
                          p->RFTempR  = this->data->RFtempR->value[0].toFloat();
                          p->RFTempCL  = this->data->RFtempCL->value[0].toFloat();
                          p->RFTempCM  = this->data->RFtempCM->value[0].toFloat();
                          p->RFTempCR  = this->data->RFtempCR->value[0].toFloat();
                          p->RFWearL  = this->data->RFwearL->value[0].toFloat();
                          p->RFWearM  = this->data->RFwearM->value[0].toFloat();
                          p->RFWearR  = this->data->RFwearR->value[0].toFloat();
                          p->LFSpeed  = this->data->LFspeed->value[0].toFloat();
                          p->LFPressure  = this->data->LFpressure->value[0].toFloat();
                          p->LFColdPressure  =this->data->LFcoldPressure->value[0].toFloat();
                          p->LFTempL  = this->data->LFtempL->value[0].toFloat();
                          p->LFTempM  = this->data->LFtempM->value[0].toFloat();
                          p->LFTempR  = this->data->LFtempR->value[0].toFloat();
                          p->LFTempCL  = this->data->LFtempCL->value[0].toFloat();
                          p->LFTempCM  = this->data->LFtempCM->value[0].toFloat();
                          p->LFTempCR  = this->data->LFtempCR->value[0].toFloat();
                          p->LFWearL  = this->data->LFwearL->value[0].toFloat();
                          p->LFWearM  = this->data->LFwearM->value[0].toFloat();
                          p->LFWearR  = this->data->LFwearR->value[0].toFloat();
                          p->LFRideHeight  = this->data->LFrideHeight->value[0].toFloat();
                          p->RFRideHeight  = this->data->RFrideHeight->value[0].toFloat();
                          p->LRRideHeight  = this->data->LRrideHeight->value[0].toFloat();
                          p->RRRideHeight  = this->data->RRrideHeight->value[0].toFloat();
                          p->CFSRideHeight = this->data->CFSRrideHeight->value[0].toFloat();


                          if(this->data->LFwearL->value[0].toFloat() < lf){
                              lf = this->data->LFwearL->value[0].toFloat();
                            }
                          if(this->data->LFwearM->value[0].toFloat() < lf){
                              lf = this->data->LFwearM->value[0].toFloat();
                            }
                          if(this->data->LFwearR->value[0].toFloat() < lf){
                              lf = this->data->LFwearR->value[0].toFloat();
                            }
                          if(this->data->RFwearL->value[0].toFloat() < rf){
                              rf = this->data->RFwearL->value[0].toFloat();
                            }
                          if(this->data->RFwearM->value[0].toFloat() < rf){
                              rf = this->data->RFwearM->value[0].toFloat();
                            }
                          if(this->data->RFwearR->value[0].toFloat() < rf){
                              rf = this->data->RFwearR->value[0].toFloat();
                            }
                          if(this->data->LRwearL->value[0].toFloat() < lr){
                              lr = this->data->LRwearL->value[0].toFloat();
                            }
                          if(this->data->LRwearM->value[0].toFloat() < lr){
                              lr = this->data->LRwearM->value[0].toFloat();
                            }
                          if(this->data->LRwearR->value[0].toFloat() < lr){
                              lr = this->data->LRwearR->value[0].toFloat();
                            }
                          if(this->data->RRwearL->value[0].toFloat() < rr){
                              rr = this->data->RRwearL->value[0].toFloat();
                            }
                          if(this->data->RRwearM->value[0].toFloat() < rr){
                              rr = this->data->RRwearM->value[0].toFloat();
                            }
                          if(this->data->RRwearR->value[0].toFloat() < rr){
                              rr = this->data->RRwearR->value[0].toFloat();
                            }
                            }else{
                              qDebug() << "INVALID DISTANCE "<< distpct;
                            }
                        }




                  }
                  dc->closeFile();
                  this->save_done = false;
                  emit this->new_telemetrydata(save);
                  while(this->save_done == false){
                      l_event.processEvents();
                      QThread::msleep(10);
                  }
                  emit this->new_tyre_wear(lf, rf, lr, rr, 0);
                  emit this->reading_done();
                  delete dc;
                  delete sessionstring;
                  delete save;
                  QFile f(this->filenames[filenameindex]);
                  f.remove();
                }
            }

        }

      l_event.processEvents();
      QThread::msleep(100);
    }
}

void TelemetryReader::save_finished(){
    this->save_done = true;
}