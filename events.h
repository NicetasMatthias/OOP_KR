#ifndef EVENTS_H
#define EVENTS_H

#include <state.h>
#include <QString>


enum Events
{
    REQUEST = 1,
    RESET,
    CARARRIVAL,
    TRUCKARRIVAL,
    CAR1READY,
    CAR2READY,
    CAR3READY,
    TRUCK1READY,
    TRUCK2READY,
};

struct Response
{
    State d;
    QString s;
    bool is_text = true;
};

#endif // EVENTS_H
