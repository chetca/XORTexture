#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(256, 256);
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter painter;
    painter.begin(this);
    QImage img(width(),height(),QImage::Format_RGB32);
    QRgb rgb;
    for (int x=0; x<width(); x++) {
        for (int y=0; y<height(); y++) {
            unsigned char c = x ^ y;
            rgb = qRgb(255-c,c,c%64);
            img.setPixel (x,y,rgb);
        }
    }
    painter.drawImage(0,0,img);
    painter.end();
}
