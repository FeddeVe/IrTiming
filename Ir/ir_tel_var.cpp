#include "ir_tel_var.h"

ir_tel_var::ir_tel_var(QObject *parent, QString name) : QObject(parent)
{
  this->name = name;
  this->isinit = false;
  this->idx_addres = -1;
}

void ir_tel_var::set_var_hdr(const irsdk_varHeader *v){
  this->type = v->type;
  this->name = v->name;
  this->idx_addres = v->offset;
  this->count = v->count;
  for(int i = 0; i < 64; i++){
      this->value[i] = 0;
    }
  this->isinit = true;
}

void ir_tel_var::set_raw_data(char *m_data){
  const char * data = m_data + this->idx_addres;
  for(int i = 0; i < this->count; i++){
                      switch(this->type)
                      {

                      // 1 byte
                      case irsdk_char:
                          {
                          char res = (((const char*)data)[i]);
                          if(res != this->value[i].toChar()){
                              this->value[i] = res;
                              //emit this->value_update(i, this);
                            }
                          }
                          break;
                      case irsdk_bool:
                          {
                          bool res = (((const char*)data)[i]);
                            if(res != this->value[i].toBool()){
                                this->value[i] = res;
                                //emit this->value_update(i, this);
                              }
                          }
                          break;
                      // 4 bytes
                      case irsdk_int:
                      case irsdk_bitField:
                          {
                            int res = (((const int*)data)[i]);


                            if(res != this->value[i].toInt()){
                                this->value[i] = res;
                               // emit this->value_update(i, this);
                              }
                          }
                              break;

                      // test float/double for greater than 1.0 so that
                      // we have a chance of this being usefull
                      // technically there is no right conversion...
                      case irsdk_float:
                          {
                            float res = (((const float*)data)[i]);
                            if(res != this->value[i].toFloat()){
                                this->value[i] = res;
                               // emit this->value_update(i, this);
                              }
                          }
                              break;

                      // 8 bytes
                      case irsdk_double:
                          {
                            double res = (((const double*)data)[i]);
                            if(res != this->value[i].toDouble()){
                                this->value[i] = res;
                                //emit this->value_update(i, this);
                              }

                          }
                              break;
                      }
    }
}
