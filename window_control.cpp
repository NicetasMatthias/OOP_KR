#include "window_control.h"
#include "ui_window_control.h"

Window_control::Window_control(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window_control)
{
    ui->setupUi(this);
}

Window_control::~Window_control()
{
    delete ui;
}

void Window_control::on_pushButton_car1_clicked()
{
    emit sendControl(CAR1READY);
}

void Window_control::on_pushButton_car2_clicked()
{
    emit sendControl(CAR2READY);
}

void Window_control::on_pushButton_car3_clicked()
{
    emit sendControl(CAR3READY);
}

void Window_control::on_pushButton_truck1_clicked()
{
    emit sendControl(TRUCK1READY);
}

void Window_control::on_pushButton_truck2_clicked()
{
    emit sendControl(TRUCK2READY);
}

void Window_control::on_pushButton_car_clicked()
{
    emit sendControl(CARARRIVAL);
}

void Window_control::on_pushButton_truck_clicked()
{
    emit sendControl(TRUCKARRIVAL);
}

void Window_control::on_pushButton_reset_clicked()
{
    emit sendControl(RESET);
}
