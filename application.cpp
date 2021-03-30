#include "application.h"

Application::Application(int argc, char** argv) : QApplication(argc,argv)
{
    interface = new Interface;
    interface->show();
    model = new Model;

    connect(interface,SIGNAL(sendEvent(Events)),
            model,SLOT(recieveEvent(Events)));
    connect(model,SIGNAL(sendResponse(Response)),
            interface,SLOT(reciveResponse(Response)));

}


Application::~Application()
{
    delete interface;
    delete model;
}
