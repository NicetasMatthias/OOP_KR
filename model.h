#ifndef MODEL_H
#define MODEL_H

#include <QObject>

#include <events.h>
#define MAX_P 4 //максимально количество мест на парковке

class Model : public QObject
{
    Q_OBJECT

    static State DefaultState;
    State state;

    void arrive(bool); //true - означает прибытие грузовика, false - легковой машины
    void release(bool, short); //true - означает отбытие грузовика, false - легковой машины, число означает номер колонки, которая освободилась

    int freePlaces();

    void request();
    void reset();
public:
    Model();

signals:
    void sendResponse(Response);
public slots:
    void recieveEvent(Events);

};

#endif // MODEL_H
