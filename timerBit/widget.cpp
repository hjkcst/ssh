#include "widget.h"
#include "ui_widget.h"
#include<QTextCodec>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    time = new QTime;  //时间类
//    timer = new QTimer;//定时类
//QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());//设置tr()所需要的字符集
//QObject::tr("中文");

    QTextCodec *code = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(code);
    connect(&timer,SIGNAL(timeout()),this,SLOT(setTime()));
    time.setHMS(0,0,0,0);
    ui->label_bt->setText("00:00:00:000");


}

Widget::~Widget()
{
    delete ui;
}

void Widget::setTime()
{
     time=time.addMSecs(40);//每次加20毫秒
    ui->label_bt->setText(time.toString("hh:mm:ss:zzz"));
}


void Widget::on_start_bt_clicked()
{
    timer.start(30);

}

void Widget::on_bit_bt_clicked()
{
    QString temp;
    i=i+1;
    temp.sprintf("第%d名:",i);
    ui->text_bt->append(temp);
   ui->text_bt->append(time.toString("hh:mm:ss.zzz"));
}

void Widget::on_reset_bt_clicked()
{
    timer.stop();
    time.setHMS(0,0,0,0);
    ui->label_bt->setText("00:00:00:000");
    ui->text_bt->clear();

}

void Widget::on_stop_bt_clicked()
{
    timer.stop();

}
