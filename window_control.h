#ifndef WINDOW_CONTROL_H
#define WINDOW_CONTROL_H

#include <QWidget>
#include <events.h>

namespace Ui {
class Window_control;
}

class Window_control : public QWidget
{
    Q_OBJECT

public:
    explicit Window_control(QWidget *parent = nullptr);
    ~Window_control();

private:
    Ui::Window_control *ui;

signals:
    void sendControl(Events);
private slots:
    void on_pushButton_car1_clicked();
    void on_pushButton_car2_clicked();
    void on_pushButton_car3_clicked();
    void on_pushButton_truck1_clicked();
    void on_pushButton_truck2_clicked();
    void on_pushButton_car_clicked();
    void on_pushButton_truck_clicked();
    void on_pushButton_reset_clicked();
};

#endif // WINDOW_CONTROL_H
