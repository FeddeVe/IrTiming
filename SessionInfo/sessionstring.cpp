#include "sessionstring.h"

SessionString::SessionString(QObject *parent) : QObject(parent)
{
  this->changed = false;
  this->str_SessionString = "";

  this->weekendinfo = new WeekendInfo(this);
  this->weekendoptions = new WeekendOptions(this);
  this->telemetryoptions = new TelemetryOptions(this);
  this->sessioninfo = new SessionInfo(this);
  this->driverinfo = new DriverInfo(this);
  this->splittimeinfo = new SplitTimeInfo(this);
}

void SessionString::set_sessionstring(QString str){
  this->str_SessionString = str;
  this->changed = true;
  //this->singleshot();
}


void SessionString::singleshot(){
  YAML::Node node = YAML::Load(this->str_SessionString.toStdString());
  if(node.IsMap()){

      for(YAML::iterator it = node.begin(); it != node.end(); it++){
           YAML::Node key = it->first;
           YAML::Node value = it->second;

        if(value.IsMap()){

     //  qDebug() << "ISMAP";
       QString item = QString::fromStdString(key.as<string>());
     //  qDebug() <<"ISSCALAR - " << item;
       if(item == "WeekendInfo"){
           this->process_weekendinfo(value);
         }else if(item == "SessionInfo"){
           //this->process_sessioninfo(value);
       }else if(item == "CameraInfo"){
           //currently nothing to do with this.... skipping this part
       }else if(item == "RadioInfo"){
            //currently nothing to do with this.... skipping this part
       }else if(item == "DriverInfo"){
           //this->process_driverinfo(value);
         }else if(item == "SplitTimeInfo"){
           //this->process_splittimeinfo(value);
         }else if(item == "CarSetup"){
            //currently nothing to do with this.... skipping this part
       }else{
           qDebug() << "UNUSED MAP "<< item;
         }

        }else if(value.IsNull()){
            qDebug() << "ISNULL";
        }else if(value.IsScalar()){
qDebug() << "ISCALAR";
        }else if(value.IsSequence()){
            qDebug() << "ISSEQUENCE";
        }else{
            qDebug() << "WEET  IK VEEL";
        }



      //   std::string key = it->first.as<std::string>();
      //   string val = it->second.as<string>();// <- key
      //  qDebug() << QString::fromStdString(key) << ":" << QString::fromStdString(val);

      }
  }else{
       for(YAML::iterator it = node.begin(); it != node.end(); it++){

          YAML::Node key = it->first;

           qDebug() <<"IT : "<< (it->Type()) << "  " << QString::fromStdString(key.Tag());

       }
  }
  // emit this->new_sessionstring(this);




}

void SessionString::process(){
  QEventLoop l;

  this-> exit = false;
  while(this->exit == false){
      if(this->changed){
          this->changed = false;
           this->splittimeinfo->clear();
           this->driverinfo->clear();



          YAML::Node node = YAML::Load(this->str_SessionString.toStdString());


          if(node.IsMap()){
              qDebug() << "ISMAP";


              for(YAML::iterator it = node.begin(); it != node.end(); it++){
                   YAML::Node key = it->first;
                   YAML::Node value = it->second;

                if(value.IsMap()){

             //  qDebug() << "ISMAP";
               QString item = QString::fromStdString(key.as<string>());
             //  qDebug() <<"ISSCALAR - " << item;
               if(item == "WeekendInfo"){
                   this->process_weekendinfo(value);
                 }else if(item == "SessionInfo"){
                   this->process_sessioninfo(value);
               }else if(item == "CameraInfo"){
                   //currently nothing to do with this.... skipping this part
               }else if(item == "RadioInfo"){
                    //currently nothing to do with this.... skipping this part
               }else if(item == "DriverInfo"){
                   this->process_driverinfo(value);
                 }else if(item == "SplitTimeInfo"){
                   this->process_splittimeinfo(value);
                 }else if(item == "CarSetup"){
                    //currently nothing to do with this.... skipping this part
               }else{
                   qDebug() << "UNUSED MAP "<< item;
                 }

                }else if(value.IsNull()){
                    qDebug() << "ISNULL";
                }else if(value.IsScalar()){
       qDebug() << "ISCALAR";
                }else if(value.IsSequence()){
                    qDebug() << "ISSEQUENCE";
                }else{
                    qDebug() << "WEET  IK VEEL";
                }



              //   std::string key = it->first.as<std::string>();
              //   string val = it->second.as<string>();// <- key
              //  qDebug() << QString::fromStdString(key) << ":" << QString::fromStdString(val);

              }
          }else{
               for(YAML::iterator it = node.begin(); it != node.end(); it++){

                  YAML::Node key = it->first;

                   qDebug() <<"IT : "<< (it->Type()) << "  " << QString::fromStdString(key.Tag());

               }
          }





          int bp = 0;
          bp++;





          emit this->new_sessionstring(this);
        }

      l.processEvents();
      QThread::msleep(100);
    }

}

void SessionString::process_weekendinfo(YAML::Node n){

 for(YAML::iterator it = n.begin(); it != n.end(); it++){
     YAML::Node key = it->first;
     YAML::Node value = it->second;

  if(value.IsMap()){
    QString k = QString::fromStdString(key.as<string>());

     if(k == "WeekendOptions"){
         this->process_weekendoptions(value);
     }else if(k == "TelemetryOptions"){
         this->process_telemetryoptions(value);
     }else{
         qDebug() << "IsMap  " << k;
     }


  }
  if(value.IsNull()){
       QString item = QString::fromStdString(key.as<string>());
       this->weekendinfo->set_value(item, "");
  }
  if(value.IsScalar()){
      QString item = QString::fromStdString(key.as<string>());
      QString val = QString::fromStdString(value.as<string>());

      this->weekendinfo->set_value(item, val);
  }
  if(value.IsSequence()){

  }

 }


}

void SessionString::process_weekendoptions(YAML::Node n){


 for(YAML::iterator it = n.begin(); it != n.end(); it++){
     YAML::Node key = it->first;
     YAML::Node value = it->second;

  if(value.IsMap()){
    QString k = QString::fromStdString(key.as<string>());
     qDebug() << "ISMAP  "  << k;
  }
  if(value.IsNull()){
      QString item = QString::fromStdString(key.as<string>());

      this->weekendoptions->set_value(item,  "");
  }
  if(value.IsScalar()){
      QString item = QString::fromStdString(key.as<string>());
      QString val = QString::fromStdString(value.as<string>());

      this->weekendoptions->set_value(item,  val);
  }
  if(value.IsSequence()){

  }

 }




}

void SessionString::process_telemetryoptions(YAML::Node n){


 for(YAML::iterator it = n.begin(); it != n.end(); it++){
     YAML::Node key = it->first;
     YAML::Node value = it->second;

  if(value.IsMap()){
    QString k = QString::fromStdString(key.as<string>());
     qDebug() << "ISMAP  "  << k;
  }
  if(value.IsNull()){
      QString item = QString::fromStdString(key.as<string>());
     this->telemetryoptions->set_value(item, "");
  }
  if(value.IsScalar()){
      QString item = QString::fromStdString(key.as<string>());
      QString val = QString::fromStdString(value.as<string>());
this->telemetryoptions->set_value(item, val);

  }
  if(value.IsSequence()){

  }

 }


}

void SessionString::process_sessioninfo(YAML::Node n){

 for(YAML::iterator it = n.begin(); it != n.end(); it++){
     YAML::Node key = it->first;
     YAML::Node value = it->second;

  if(value.IsMap()){
    QString k = QString::fromStdString(key.as<string>());
     qDebug() << "ISMAP  "  << k;
  }
  if(value.IsNull()){
      QString item = QString::fromStdString(key.as<string>());

  }
  if(value.IsScalar()){
      QString item = QString::fromStdString(key.as<string>());
      QString val = QString::fromStdString(value.as<string>());


  }
  if(value.IsSequence()){


      int sessionindex = 0;

      for(YAML::iterator it2 = value.begin(); it2 != value.end(); it2++){

           if(it2->IsMap()){
               for(YAML::iterator it3 = it2->begin(); it3 != it2->end(); it3++){
                   YAML::Node f = it3->first;
                   YAML::Node s = it3->second;

                   if(s.IsScalar()){
                       QString item = QString::fromStdString(f.as<string>());
                       QString value = QString::fromStdString(s.as<string>());
                       this->sessioninfo->Put_From_Yaml(sessionindex, item, value);
                   }else if(s.IsNull()){
                       QString item = QString::fromStdString(f.as<string>());
                       QString value = QString::fromStdString(s.as<string>());
                       this->sessioninfo->Put_From_Yaml(sessionindex, item, "");
                   }else if(s.IsMap()){
                       QString item = QString::fromStdString(it3->as<string>());
                       //QString value = QString::fromStdString(s.as<string>());
                       qDebug() << "ISMAP"  << item;
                   }else if(s.IsSequence()){
                         QString item = QString::fromStdString(f.as<string>());
                       //QString item = QString::fromStdString(it3->as<string>());
                       //QString value = QString::fromStdString(s.as<string>());
                         if(item == "ResultsPositions"){
                             this->process_sessioninfo_resultposition(sessionindex, s);
                         }

                   }
               }
           }

           sessionindex++;
        }
  }

 }

}

void SessionString::process_sessioninfo_resultposition(int sessionindex, YAML::Node n){

    int resultindex = 0;
    for(YAML::iterator it = n.begin(); it != n.end(); it++){
        if(it->IsMap()){
            for(YAML::iterator it2 = it->begin(); it2 != it->end(); it2++){
                YAML::Node key = it2->first;
                YAML::Node value = it2->second;
                if(value.IsNull()){
                    QString item = QString::fromStdString(key.as<string>());

                      this->sessioninfo->Put_resultposition_from_yaml(sessionindex, resultindex, item, "");
                }
                if(value.IsScalar()){
                    QString item = QString::fromStdString(key.as<string>());
                    QString val = QString::fromStdString(value.as<string>());



                    this->sessioninfo->Put_resultposition_from_yaml(sessionindex, resultindex, item, val);

                }


            }
        }
        resultindex++;


    }

}

void SessionString::process_driverinfo(YAML::Node n){


   for(YAML::iterator it = n.begin(); it != n.end(); it++){
       YAML::Node key = it->first;
       YAML::Node value = it->second;

    if(value.IsMap()){
      QString k = QString::fromStdString(key.as<string>());
       qDebug() << "ISMAP  "  << k;
    }
    if(value.IsNull()){
        QString item = QString::fromStdString(key.as<string>());

        this->driverinfo->set_value(item, "");

    }
    if(value.IsScalar()){
        QString item = QString::fromStdString(key.as<string>());
        QString val = QString::fromStdString(value.as<string>());


         this->driverinfo->set_value(item, val);


    }
    if(value.IsSequence()){


        int driverindex = 0;

        for(YAML::iterator it2 = value.begin(); it2 != value.end(); it2++){

             if(it2->IsMap()){
                 for(YAML::iterator it3 = it2->begin(); it3 != it2->end(); it3++){
                     YAML::Node f = it3->first;
                     YAML::Node s = it3->second;

                     if(s.IsScalar()){
                         QString item = QString::fromStdString(f.as<string>());
                         QString value = QString::fromStdString(s.as<string>());
                         this->driverinfo->set_driver_value(driverindex, item, value);

                     }else if(s.IsNull()){
                         QString item = QString::fromStdString(f.as<string>());
                         QString value = QString::fromStdString(s.as<string>());
                          this->driverinfo->set_driver_value(driverindex, item, "");


                     }else if(s.IsMap()){
                         QString item = QString::fromStdString(it3->as<string>());
                         //QString value = QString::fromStdString(s.as<string>());
                         qDebug() << "ISMAP"  << item;
                     }else if(s.IsSequence()){
                           QString item = QString::fromStdString(f.as<string>());
                         //QString item = QString::fromStdString(it3->as<string>());
                         //QString value = QString::fromStdString(s.as<string>());


                     }
                 }
             }

             driverindex++;

          }
    }

   }

}

void SessionString::process_splittimeinfo(YAML::Node n){

  for(YAML::iterator it = n.begin(); it != n.end(); it++){
      YAML::Node key = it->first;
      YAML::Node value = it->second;

   if(value.IsMap()){
     QString k = QString::fromStdString(key.as<string>());
      qDebug() << "ISMAP  "  << k;
   }
   if(value.IsNull()){
       QString item = QString::fromStdString(key.as<string>());

       //this->m->driverinfo->set_value(item, "");
       qDebug() << "IsNULL " << item;

   }
   if(value.IsScalar()){
       QString item = QString::fromStdString(key.as<string>());
       QString val = QString::fromStdString(value.as<string>());

       qDebug() << "IsScalar " << item << " - "<< val;

        //this->m->driverinfo->set_value(item, val);


   }
   if(value.IsSequence()){


       int sectorindex = 0;

       for(YAML::iterator it2 = value.begin(); it2 != value.end(); it2++){

            if(it2->IsMap()){
                for(YAML::iterator it3 = it2->begin(); it3 != it2->end(); it3++){
                    YAML::Node f = it3->first;
                    YAML::Node s = it3->second;

                    if(s.IsScalar()){
                        QString item = QString::fromStdString(f.as<string>());
                        QString value = QString::fromStdString(s.as<string>());
                       // this->m->driverinfo->set_driver_value(driverindex, item, value);

                        this->splittimeinfo->set_sector(sectorindex, item, value);
                    }else if(s.IsNull()){
                        QString item = QString::fromStdString(f.as<string>());
                        QString value = QString::fromStdString(s.as<string>());
                       //  this->m->driverinfo->set_driver_value(driverindex, item, "");

                        this->splittimeinfo->set_sector(sectorindex, item, "");

                    }else if(s.IsMap()){
                        QString item = QString::fromStdString(it3->as<string>());
                        //QString value = QString::fromStdString(s.as<string>());
                        qDebug() << "ISMAP"  << item;
                    }else if(s.IsSequence()){
                          QString item = QString::fromStdString(f.as<string>());
                        //QString item = QString::fromStdString(it3->as<string>());
                        //QString value = QString::fromStdString(s.as<string>());


                    }
                }
            }

            sectorindex++;

         }
     }
    }

}
