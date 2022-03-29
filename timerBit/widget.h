#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTime>
#include<QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();



private slots:
    void on_start_bt_clicked();

    void on_bit_bt_clicked();

    void on_reset_bt_clicked();

    void on_stop_bt_clicked();

    void setTime();
private:
    Ui::Widget *ui;
    QTime time;
    QTimer timer;
    int i=0;
};
#endif // WIDGET_H
