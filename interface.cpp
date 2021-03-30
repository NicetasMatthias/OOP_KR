#include "interface.h"
#include "ui_interface.h"

Interface::Interface() :
    QWidget(),
    ui(new Ui::Interface)
{
    ui->setupUi(this);
    //emit sendEvent(REQUEST);

    connect(&control,SIGNAL(sendControl(Events)),
            this,SLOT(reciveControl(Events)));
}

Interface::~Interface()
{
    delete ui;
}

void Interface::reciveControl(Events ev)
{
    emit sendEvent(ev);
}

void Interface::reciveResponse(Response rs)
{
    info.set(rs.d);
    if (rs.is_text)
    {
        log.add(rs.s);
    }
}

void Interface::closeEvent(QCloseEvent* ev)
{
    control.close();
    info.close();
    log.close();
    ev->accept();
}

void Interface::on_pushButton_control_clicked()
{
    control.show();
}

void Interface::on_pushButton_info_clicked()
{
    info.show();
    emit sendEvent(REQUEST);
}

void Interface::on_pushButton_log_clicked()
{
    log.show();
}
