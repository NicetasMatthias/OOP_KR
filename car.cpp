#include "car.h"

#define CAR_SIZE 1
#define TRUCK_SIZE 2


Car::Car()
{
    is_truck_var=false;
    size=1;
}

Car::Car(bool t)
{
    is_truck_var=t;
    if (t) size = TRUCK_SIZE;
    else size = CAR_SIZE;

}

int Car::get_size()
{
    return size;
}

bool Car::is_truck()
{
    return is_truck_var;
}
