#ifndef STATE_H
#define STATE_H

struct State
{
    bool car_gas[3];
    bool truck_gas[2];
    short parking_car;
    short parking_truck;
    State() {}
    State(bool c1,bool c2,bool c3,bool t1,bool t2,short n1,short n2)
    {
        car_gas[0]=c1;
        car_gas[1]=c2;
        car_gas[2]=c3;
        truck_gas[0]=t1;
        truck_gas[1]=t2;
        parking_car = n1;
        parking_truck = n2;
    }
};




#endif // STATE_H

