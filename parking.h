#ifndef PARKING_H
#define PARKING_H

#include <QObject>
#include <QVector>
#include <car.h>

class Parking
{
public:
    Parking();
    int get_num_of_cars();
    int get_num_of_trucks();
    int add_car(Car*);
    void reset();
    Car* pick_car(bool);

private:
    int get_free_places();
    QVector <Car*> cars;
    int max_places;
};

#endif // PARKING_H
