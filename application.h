#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

#include <interface.h>
#include <model.h>

class Application : public QApplication
{
    Q_OBJECT
private:
    Model *model;
    Interface *interface;

public:
    Application(int,char**);
    ~Application();
};

#endif // APPLICATION_H
