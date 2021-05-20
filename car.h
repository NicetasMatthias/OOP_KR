#ifndef CAR_H
#define CAR_H

#include <QObject>

class Car
{
public:
    Car();
    Car(bool);
    int get_size();
    bool is_truck();

private:
    bool is_truck_var;
    int size;
};

#endif // CAR_H
