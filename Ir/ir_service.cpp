#include "ir_service.h"

ir_service::ir_service(QObject *parent, Master *refmaster) : QObject(parent)
{
  this->refmaster = refmaster;
  this->s = new SessionString(this);
  this->sdk = new irsdk_utils();
  this->connected = false;
  this->oldtickcount = 0;
  this->oldsessioninfo = 0;
  this->vars = new ir_tel_vars(this);
  this->missing_steps = 0;
  this->old_sessiontick = 0;
}

void ir_service::write_variables(){
  QString output1 = "";
  QString output = "<html><body><table>";
  output+="<tr><th>NAME</th><th>DESCRIPTION</th><th>TYPE</th><th>UNIT</th><th>count</th></tr>";
  const irsdk_header *hdr =  this->sdk->irsdk_getHeader();
  const irsdk_varHeader *pVar;
  QString types[6] = {"irsdk_char", "irsdk_bool", "irsdk_int", "irsdk_bitField", "irsdk_float", "irsdk_double"};

                  for(int index=0; index<hdr->numVars; index++)
                  {                      
                         pVar = this->sdk->irsdk_getVarHeaderEntry(index);
                         output1+="this->"+ QString(pVar->name) +" = new ir_tel_var(this, \"" + QString(pVar->name) +");\n";
                         output1+="this->all_vars.push_back(this->"+ QString(pVar->name) +");\n";
                         output+="<tr><td> "+ QString(pVar->name) + "</td><td>" + pVar->desc +"</td><td>"+ QString::number(pVar->type) + "//"+ types[pVar->type] +"</td><td>"+ pVar->unit +"</td><td>"+ QString::number(pVar->count) +"</td></tr>";

                         for(int y = 0; y < this->vars->all_vars.count(); y++){
                           if(this->vars->all_vars[y]->name == pVar->name){
                               this->vars->all_vars[y]->set_var_hdr(pVar);
                               break;
                             }
                          }
                  }
                  int bp = 0;
                  output+="</table></html>";
                  QFile file(QCoreApplication::applicationDirPath() +"/all_vars.html");
                  if (!file.open(QIODevice::Truncate | QIODevice::WriteOnly)) {
                      qDebug("Basically, now we lost content of a file");
                    //  return;
                  }
                //  QByteArray xml = doc.toByteArray();
                  file.write(output.toUtf8());
                  file.close();
                  emit this->output1(output1);
}

void ir_service::process(){
  this->exit = false;
  bool oke = false;
  QEventLoop l;
  while(this->exit == false){
    this->firt_run = true;
    oke = this->sdk->irsdk_startup();
    if(oke){
        this->write_variables();
        m_nData = sdk->irsdk_getHeader()->bufLen;
        m_data = new char[m_nData];
       bool ok = true;
        int sleeper = 2;
    while(oke){
        ok = this->sdk->irsdk_waitForDataReady(1, m_data);
        if(ok){
            if(this->connected == false){
                this->connected = true;
                emit this->connection_changed(this->connected);
              }

          //  if(this->isreplayplaying->value[0] ==0){
            for(int i = 0; i < this->vars->all_vars.count(); i++){
                this->vars->all_vars[i]->set_raw_data(m_data);
              }
            if(this->old_sessiontick == 0){
                this->old_sessiontick = this->vars->SessionTick->value[0].toInt();
              }
            int diff = this->vars->SessionTick->value[0].toInt() - this->old_sessiontick;
            if(diff > 1){
                this->missing_steps = this->missing_steps+diff;
              //  qDebug() << "Missing Steps: "<< this->missing_steps;
              }
            this->old_sessiontick = this->vars->SessionTick->value[0].toInt();
          //  }

            QString path = QCoreApplication::applicationDirPath();
            if(this->sdk->irsdk_getHeader()->sessionInfoUpdate != this->oldsessioninfo){
               // qDebug() << "SESSION INFO UPDATED";
                QFile file(QCoreApplication::applicationDirPath() +"/SessionInfo.txt");
                if (!file.open(QIODevice::Truncate | QIODevice::WriteOnly)) {
                    qDebug("Basically, now we lost content of a file");
                  //  return;
                }
                QString output = this->sdk->irsdk_getSessionInfoStr();
                file.write(output.toUtf8());
                file.close();
                emit this->new_sessionstring(this->sdk->irsdk_getSessionInfoStr());
               // this->refmaster->sessionstring->set_sessionstring(this->sdk->irsdk_getSessionInfoStr());
               // this->refmaster->sessionstring->singleshot();
                //this->s->set_sessionstring(this->sdk->irsdk_getSessionInfoStr());
               // this->s->singleshot();
               // this->refmaster->core->sessionstring_update(this->s);
                this->oldsessioninfo = this->sdk->irsdk_getHeader()->sessionInfoUpdate;
              }


          //  this->refmaster->sessionuid = this->vars->SessionUniqueID->value[0].toInt();

            int bp = 0;

/*
            for(int i = 0; i < this->vars.count(); i++){
                //if((this->vars[i]->getRegistered()) || (this->vars[i]->getName() == "SessionTick")){
                this->vars[i]->set_raw_data(m_data);
                if(vars[i]->getName() == "SessionTime"){
                   this->refmaster->vars->sessiontime = this->vars[i]->getValue(0).toDouble();
                  }else if(this->vars[i]->getName() == "SessionTick"){
                    this->refmaster->vars->sessiontick = this->vars[i]->getValue(0).toInt();
                  }else if(this->vars[i]->getName() == "SessionNum"){
                    this->refmaster->vars->sessionnum = this->vars[i]->getValue(0).toInt();
                  }else if(this->vars[i]->getName() == "SessionState"){
                    this->refmaster->vars->sessionstate = this->vars[i]->getValue(0).toInt();
                  }else if(this->vars[i]->getName() == "SessionUniqueID"){
                    this->refmaster->vars->sessionuniqueid = this->vars[i]->getValue(0).toInt();
                  }else if(this->vars[i]->getName() == "SessionFlags"){
                    this->refmaster->vars->sessionflags  = this->vars[i]->getValue(0).toInt();
                  }else if(this->vars[i]->getName() == "SessionTimeRemain"){
                    this->refmaster->vars->sessiontimeremain = this->vars[i]->getValue(0).toInt();
                  }else if(this->vars[i]->getName() =="SessionLapsRemain"){
                    this->refmaster->vars->sessionlapsremain = this->vars[i]->getValue(0).toInt();
                  }else if(this->vars[i]->getName() == "SessionLapsRemainEx"){
                    this->refmaster->vars->sessionlaptsremainEX = this->vars[i]->getValue(0).toInt();
                  }else if(this->vars[i]->getName() == "SessionTimeOfDay"){
                    this->refmaster->vars->sessiontimeofday = this->vars[i]->getValue(0).toFloat();
                  }else if(this->vars[i]->getName() == "CarIdxLap"){
                    for(int y = 0; y < 64; y++){
                        this->refmaster->vars->CarIdxLap[y] = this->vars[i]->getValue(y).toInt();
                      }
                  }else if(this->vars[i]->getName() == "CarIdxLapComplete"){
                    for(int y = 0 ; y < 64; y++){
                        this->refmaster->vars->CarIdxLapCompleted[y] = this->vars[i]->getValue(y).toInt();
                      }
                  }else if(this->vars[i]->getName() == "CarIdxLapDistPct"){
                    for(int y = 0; y < 64; y ++){
                        this->refmaster->vars->CarIdxLapDistPct[y] = this->vars[i]->getValue(y).toFloat();
                      }
                  }else if(this->vars[i]->getName() == "CarIdxTrackSurface"){
                    for(int y = 0; y < 64; y++){
                        this->refmaster->vars->CarIdxTrackSurface[y] = this->vars[i]->getValue(y).toInt();
                      }
                  }else if(this->vars[i]->getName() == "CarIdxTrackSurfaceMaterial"){
                    for(int y = 0; y < 64; y++){
                        this->refmaster->vars->CarIdxTrackSurfaceMaterial[y] = this->vars[i]->getValue(y).toInt();
                      }
                  }else if(this->vars[i]->getName() == "CarIdxOnPitRoad"){
                    for(int y = 0; y < 64; y++){
                        this->refmaster->vars->CarIdxOnPitRoad[y] = this->vars[i]->getValue(y).toBool();
                      }
                  }else if(this->vars[i]->getName() == "CarIdxPosition"){
                    for(int y = 0;y < 64; y++){
                        this->refmaster->vars->CarIdxPosition[y] = this->vars[i]->getValue(y).toInt();
                        }
                  }else if(this->vars[i]->getName() == "CarIdxClassPosition"){
                    for(int y = 0; y < 64; y++){
                        this->refmaster->vars->CarIdxClassPosition[y] = this->vars[i]->getValue(y).toInt();
                      }
                  }else if(this->vars[i]->getName() == "CarIdxF2Time"){
                    for(int y = 0; y < 64; y++){
                        this->refmaster->vars->CarIdxF2Time[y] = this->vars[i]->getValue(y).toFloat();
                      }
                  }else if(this->vars[i]->getName() == "CarIdxEstTime"){
                    for(int y = 0; y < 64; y++){
                        this->refmaster->vars->CarIdxEstTime[y] = this->vars[i]->getValue(y).toFloat();
                      }
                  }else if(this->vars[i]->getName() == "CarIdxGear"){
                    for(int y = 0; y < 64; y++){
                        this->refmaster->vars->CarIdxGear[y] = this->vars[i]->getValue(y).toInt();
                      }
                  }else if(this->vars[i]->getName() == "CarIdxRPM"){
                                        for(int y = 0; y < 64; y++){
                                            this->refmaster->vars->CarIdxRPM[y] = this->vars[i]->getValue(y).toFloat();
                                          }



                  }else{
                    //qDebug() << "VAR NOT USED: " << this->vars[i]->getName();
                  }
                  //}

                if(this->vars[i]->getName() == "SessionTick"){
                    int val = this->vars[i]->getValue(0).toInt();
                    if((val - 1) != this->oldtickcount){
                        //qDebug() << "!!TICKCOUNT NOT REACHED!!";
                      }
                    this->oldtickcount = val;
                  }
              }
                */

            emit this->new_data_ready(this->vars);
            //this->refmaster->core->telemetry_update(this->vars);
          }

         oke = this->sdk->irsdk_isConnected();
        QThread::msleep(sleeper);
        l.processEvents();
     //   l.exec();
      }
     }
    if(this->connected != false){
    this->connected = false;

    emit this->connection_changed(this->connected);
      }

    QThread::sleep(1);
    }


    emit finished();
}

void ir_service::restart_telemetry(){
   this->sdk->irsdk_broadcastMsg(irsdk_BroadcastTelemCommand, irsdk_TelemCommand_Restart, 0);
}







