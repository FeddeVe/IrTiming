#include "tire_graph.h"
#include "ui_tire_graph.h"

Tire_Graph::Tire_Graph(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Tire_Graph)
{
  this->centerlap = 0;
  ui->setupUi(this);


}

Tire_Graph::~Tire_Graph()
{
  delete ui;
}

void Tire_Graph::paintEvent(QPaintEvent *event){
  int width = this->width();
  int height = this->height();
  int g_width = width * 0.96;
  int g_height = height *0.96;
  int top = height *0.02;
  int left = width *0.02;


  QPainter painter;
  painter.begin(this);
  QRect graph_rect;
  graph_rect.setRect(left, top, g_width, g_height);
  QBrush br_graphback;
  br_graphback.setColor(QColor::fromRgb(32,32,32));
  br_graphback.setStyle(Qt::SolidPattern);
  painter.fillRect(graph_rect, br_graphback);
  QBrush br_graphlines;
  br_graphlines.setColor(QColor::fromRgb(10,128,10));
  br_graphlines.setStyle(Qt::SolidPattern);
  painter.setBrush(br_graphlines);
  painter.setPen(QColor::fromRgb(128,128,128));
  float x_spacing = float(g_height) / float(100);
  int lap_spacing = 20;
  painter.drawLine(left, top + (x_spacing * 20), g_width + left, top+(x_spacing * 20));
  painter.drawLine(left, top + (x_spacing * 20), g_width + left, top+(x_spacing * 20));
  painter.drawLine(left, top + (x_spacing * 40), g_width + left, top+(x_spacing * 40));
  painter.drawLine(left, top + (x_spacing * 60), g_width + left, top+(x_spacing * 60));
  painter.drawLine(left, top + (x_spacing * 80), g_width + left, top+(x_spacing * 80));
  painter.drawLine(left, top + (x_spacing * 100), g_width + left, top+(x_spacing * 100));

  int lap_x = left + (g_width / 2);
  this->start_lap = this->centerlap;
  while (lap_x > left){
      painter.drawLine(lap_x, top, lap_x, top+g_height);
      painter.drawText(lap_x - 5, height, QString::number(this->start_lap));
      lap_x = lap_x - (5*lap_spacing);
      this->start_lap = this->start_lap- 5;
    }
  lap_x = left + (g_width / 2);
   lap_x = lap_x + (5*lap_spacing);
   this->end_lap = this->centerlap + 5;
   while(lap_x < left+g_width){
       painter.drawLine(lap_x, top, lap_x, top+g_height);
       painter.drawText(lap_x - 5, height, QString::number(this->end_lap));
       lap_x = lap_x + (5*lap_spacing);
       this->end_lap = this->end_lap + 5;
     }

   int i = this->start_lap;
   int x = left;
   int old_x = left;
   float old_y = 1.0f;

   float y_step = 100 / g_height;
   QColor lf_col;
   lf_col.setRgb(0,68,255);

   while(i < this->end_lap){
       if(i > 0){
            if(i < this->data.count() -1){
                int type = this->data[i]->type;
                float y2 = this->data[i]->lf;
                if(type == 2){
                    painter.setPen(Qt::PenStyle::SolidLine);
                    painter.setPen(lf_col);
                    painter.drawLine(old_x, ((1.0f - old_y) * y_step) + top, x, ((1.0f - y2) * y_step)+top);

                  }else if(type == 1){
                    painter.setPen(Qt::PenStyle::DashDotLine);
                    painter.setPen(lf_col);
                    painter.drawLine(old_x, ((1.0f - old_y) * y_step) + top, x, ((1.0f - y2) * y_step)+top);
                  }
                old_x = x;
                x = x + lap_spacing;
                old_y = y2;
              }
         }
       i = i + 1;
     }

   i = this->start_lap;
   x = left;
   old_x = left;
   old_y = 1.0f;

   y_step = 100 / g_height;

   lf_col.setRgb(128,200,0);

   while(i < this->end_lap){
       if(i > 0){
            if(i < this->data.count() -1){
                int type = this->data[i]->type;
                float y2 = this->data[i]->rf;
                if(type == 2){
                    painter.setPen(Qt::PenStyle::SolidLine);
                    painter.setPen(lf_col);
                    painter.drawLine(old_x, ((1.0f - old_y) * y_step) + top, x, ((1.0f - y2) * y_step)+top);

                  }else if(type == 1){
                    painter.setPen(Qt::PenStyle::DashDotLine);
                    painter.setPen(lf_col);
                    painter.drawLine(old_x, ((1.0f - old_y) * y_step) + top, x, ((1.0f - y2) * y_step)+top);
                  }
                old_x = x;
                x = x + lap_spacing;
                old_y = y2;
              }
         }
       i = i + 1;
     }

   i = this->start_lap;
   x = left;
   old_x = left;
   old_y = 1.0f;

   y_step = 100 / g_height;

   lf_col.setRgb(170,0,127);

   while(i < this->end_lap){
       if(i > 0){
            if(i < this->data.count() -1){
                int type = this->data[i]->type;
                float y2 = this->data[i]->rf;
                if(type == 2){
                    painter.setPen(Qt::PenStyle::SolidLine);
                    painter.setPen(lf_col);
                    painter.drawLine(old_x, ((1.0f - old_y) * y_step) + top, x, ((1.0f - y2) * y_step)+top);

                  }else if(type == 1){
                    painter.setPen(Qt::PenStyle::DashDotLine);
                    painter.setPen(lf_col);
                    painter.drawLine(old_x, ((1.0f - old_y) * y_step) + top, x, ((1.0f - y2) * y_step)+top);
                  }
                old_x = x;
                x = x + lap_spacing;
                old_y = y2;
              }
         }
       i = i + 1;
     }

   i = this->start_lap;
   x = left;
   old_x = left;
   old_y = 1.0f;

   y_step = 100 / g_height;

   lf_col.setRgb(255,170,0);

   while(i < this->end_lap){
       if(i > 0){
            if(i < this->data.count() -1){
                int type = this->data[i]->type;
                float y2 = this->data[i]->rf;
                if(type == 2){
                    painter.setPen(Qt::PenStyle::SolidLine);
                    painter.setPen(lf_col);
                    painter.drawLine(old_x, ((1.0f - old_y) * y_step) + top, x, ((1.0f - y2) * y_step)+top);

                  }else if(type == 1){
                    painter.setPen(Qt::PenStyle::DashDotLine);
                    painter.setPen(lf_col);
                    painter.drawLine(old_x, ((1.0f - old_y) * y_step) + top, x, ((1.0f - y2) * y_step)+top);
                  }
                old_x = x;
                x = x + lap_spacing;
                old_y = y2;
              }
         }
       i = i + 1;
     }



  painter.end();

}


