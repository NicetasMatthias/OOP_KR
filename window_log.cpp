#include "window_log.h"
#include "ui_window_log.h"

Window_log::Window_log(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window_log)
{
    ui->setupUi(this);

}

Window_log::~Window_log()
{
    delete ui;
}

void Window_log::add(QString s)
{
    QString tmp;
    QDateTime d = QDateTime::currentDateTime();
    tmp = "["+d.toString()+"]: "+s;
    ui->plainTextEdit->appendPlainText(tmp);
}
