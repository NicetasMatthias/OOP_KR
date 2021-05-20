#include "gas.h"

Gas::Gas()
{
    for (int i = 0; i < MAX_CAR_GAS; i++)
    {
        car_gas[i]=nullptr;
    }
    for (int i = 0; i < MAX_TRUCK_GAS; i++)
    {
        truck_gas[i]=nullptr;
    }


}

int Gas::release_car(int t)
{
    if (car_gas[t]==nullptr)
    {
        return -1;
    }
    else
    {
        delete car_gas[t];
        car_gas[t]=nullptr;
        return 0;
    }
}

int Gas::release_truck(int t)
{
    if (truck_gas[t]==nullptr)
    {
        return -1;
    }
    else
    {
        delete truck_gas[t];
        truck_gas[t]=nullptr;
        return 0;
    }
}

int Gas::add(Car *c)
{
    if(c->is_truck())
    {
        for(int i=0; i<MAX_TRUCK_GAS; i++)
        {
            if (truck_gas[i]==nullptr)
            {
                truck_gas[i]=c;
                return i+1;
            }
        }
        return -1;
    }
    else
    {
        for(int i=0; i<MAX_CAR_GAS; i++)
        {
            if (car_gas[i]==nullptr)
            {
                car_gas[i]=c;
                return i+1;
            }
        }
        return -1;
    }
}

void Gas::reset()
{
    for(int i=0; i<MAX_TRUCK_GAS; i++)
    {
        if (truck_gas[i]!=nullptr)
        {
            delete truck_gas[i];
            truck_gas[i]=nullptr;
        }
    }
    for(int i=0; i<MAX_CAR_GAS; i++)
    {
        if (car_gas[i]!=nullptr)
        {
            delete car_gas[i];
            car_gas[i]=nullptr;
        }
    }
}

void Gas::get_cars_state(bool *t)
{
    for (int i = 0; i < MAX_CAR_GAS; i++)
    {
        if (car_gas[i]==nullptr)
        {
            t[i]=false;
        }
        else
        {
            t[i]=true;
        }
    }
}

void Gas::get_trucks_state(bool *t)
{
    for (int i = 0; i < MAX_TRUCK_GAS; i++)
    {
        if (truck_gas[i]==nullptr)
        {
            t[i]=false;
        }
        else
        {
            t[i]=true;
        }
    }
}
