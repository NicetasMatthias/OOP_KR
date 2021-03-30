#ifndef WINDOW_LOG_H
#define WINDOW_LOG_H

#include <QDateTime>

#include <QWidget>

namespace Ui {
class Window_log;
}

class Window_log : public QWidget
{
    Q_OBJECT


public:
    explicit Window_log(QWidget *parent = nullptr);
    ~Window_log();

    void add(QString);

private:
    Ui::Window_log *ui;
};

#endif // WINDOW_LOG_H
