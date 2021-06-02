#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QCloseEvent>

#include <window_control.h>
#include <window_info.h>
#include <window_log.h>


namespace Ui {
class Interface;
}

class Interface : public QWidget
{
    Q_OBJECT
private:
    Window_control control;
    Window_info info;
    Window_log log;


public:
    explicit Interface();
    ~Interface();

private slots:
    void on_pushButton_control_clicked();

    void on_pushButton_info_clicked();

    void on_pushButton_log_clicked();

signals:
    void sendEvent(Events);

protected:
    void closeEvent(QCloseEvent*);

public slots:
    void reciveResponse(Response);
    void reciveControl(Events);

private:
    Ui::Interface *ui;
};

#endif // INTERFACE_H
