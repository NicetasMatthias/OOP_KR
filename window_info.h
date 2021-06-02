#ifndef WINDOW_INFO_H
#define WINDOW_INFO_H

#include <QWidget>
#include <events.h>

namespace Ui {
class Window_info;
}

class Window_info : public QWidget
{
    Q_OBJECT
private:
    static QString free, busy;

public:
    explicit Window_info(QWidget *parent = nullptr);
    ~Window_info();

    void set(State);

private:
    Ui::Window_info *ui;
};

#endif // WINDOW_INFO_H
