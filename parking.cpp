#include "parking.h"
#define MAX_P 4

Parking::Parking()
{
    max_places=MAX_P;
}

int Parking::get_free_places()
{
    int t = 0;
    for (qsizetype i = 0; i<cars.size() ; i++)
    {
        t+=cars[i]->get_size();
    }
    return max_places-t;
}


int Parking::get_num_of_cars()
{
    int t = 0;
    for (qsizetype i = 0; i<cars.size() ; i++)
    {
        if(!cars[i]->is_truck())
        {
            t++;
        }
    }
    return t;
}

int Parking::get_num_of_trucks()
{
    int t = 0;
    for (qsizetype i = 0; i<cars.size() ; i++)
    {
        if(cars[i]->is_truck())
        {
            t++;
        }
    }
    return t;
}

int Parking::add_car(Car* c)
{
    if (get_free_places()>=c->get_size())
    {
        cars.push_back(c);
        return 0;
    }
    else
    {
        return -1;
    }
}

void Parking::reset()
{
    for (qsizetype i = 0; i < cars.size(); i++)
    {
        delete cars[i];
    }
    cars.clear();
}

Car* Parking::pick_car(bool d)
{
    Car *t=nullptr;
    for (qsizetype i = 0; i < cars.size(); i++)
    {
        if (cars[i]->is_truck()==d)
        {
            t=cars[i];
            cars.remove(i);
            break;
        }
    }
    return t;
}
