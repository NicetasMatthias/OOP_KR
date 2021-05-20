#ifndef GAS_H
#define GAS_H

#define MAX_CAR_GAS 3
#define MAX_TRUCK_GAS 2

#include <QObject>
#include <car.h>



class Gas
{
public:
    Gas();
    int release_car(int);
    int release_truck(int);
    int add(Car*);
    void reset();
    void get_cars_state(bool *);
    void get_trucks_state(bool *);
private:
    Car* car_gas[MAX_CAR_GAS];
    Car* truck_gas[MAX_TRUCK_GAS];
};

#endif // GAS_H
