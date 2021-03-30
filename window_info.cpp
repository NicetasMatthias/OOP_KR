#include "window_info.h"
#include "ui_window_info.h"

QString Window_info::free = "Свободна";
QString Window_info::busy = "Занята";

Window_info::Window_info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window_info)
{
    ui->setupUi(this);
}


Window_info::~Window_info()
{
    delete ui;
}

void Window_info::set(State s)
{
    if (s.car_gas[0])  ui->lineEdit_car1->setText(busy);
    else ui->lineEdit_car1->setText(free);
    if (s.car_gas[1])  ui->lineEdit_car2->setText(busy);
    else ui->lineEdit_car2->setText(free);
    if (s.car_gas[2])  ui->lineEdit_car3->setText(busy);
    else ui->lineEdit_car3->setText(free);
    if (s.truck_gas[0]) ui->lineEdit_truck1->setText(busy);
    else ui->lineEdit_truck1->setText(free);
    if (s.truck_gas[1]) ui->lineEdit_truck2->setText(busy);
    else ui->lineEdit_truck2->setText(free);
    ui->lineEdit_cars->setText(QString::number(s.parking_car));
    ui->lineEdit_trucks->setText(QString::number(s.parking_truck));
}
