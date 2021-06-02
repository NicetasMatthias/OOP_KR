#include "model.h"

Model::Model() : QObject()
{
    p = new Parking;
    g = new Gas;
}

Model::~Model()
{
    p->reset();
    g->reset();
}

void Model::reset()
{
    Response t;
    p->reset();
    g->reset();
    t.d = get_state();
    t.s = "Протокол 'Чистый Лист'";
    emit sendResponse(t);
}

void Model::request()
{
    Response t;
    t.d = get_state();
    t.is_text = false;

    emit sendResponse(t);
}

void Model::recieveEvent(Events ev)
{
    switch (ev)
    {
    case REQUEST:
        request();
        break;
    case RESET:
        reset();
        break;
    case CARARRIVAL:
        arrive(false);
        break;
    case TRUCKARRIVAL:
        arrive(true);
        break;
    case CAR1READY:
        release(false,0);
        break;
    case CAR2READY:
        release(false,1);
        break;
    case CAR3READY:
        release(false,2);
        break;
    case TRUCK1READY:
        release(true,0);
        break;
    case TRUCK2READY:
        release(true,1);
        break;
    default: break;
    }
}

void Model::arrive(bool d)
{
    QString cr = "автомобиль";
    QString tr = "грузовик";
    Response t;
    Car *c;
    int err_c;
    c = new Car(d);

    err_c = g->add(c);
    if (err_c==-1)
    {
        err_c = p->add_car(c);
        if (err_c==-1)
        {
            t.s = "На заправку приезжает " + (d==true?tr:cr) + ", но колонки и парковка заняты и ему приходится ехать дальше";
            delete c;
        }
        else
        {
            t.s = "На заправку приезжает " + (d==true?tr:cr) + ", но колонки заняты и он встает на парковку";
        }
    }
    else
    {
        t.s = "На заправку приезжает " + (d==true?tr:cr) + " и сразу отправляется на " + QString::number(err_c) + " колонку";
    }


    t.d=get_state();
    emit sendResponse(t);
    return;
}

void Model::release(bool d, short n)
{
    QString cb = "Автомобиль";
    QString tb = "Грузовик";
    QString cm = "автомобиль";
    QString tm = "грузовик";
    Response t;
    int err_c;
    Car* c;
    if (d)
    {
        err_c = g->release_truck(n);
    }
    else
    {
        err_c = g->release_car(n);
    }

    if (err_c == 0)
    {
        t.s = (d==true?tb:cb) + " на " + QString::number(n+1) + " колонке заправился и уехал с заправки";
        t.d = get_state();
        emit sendResponse(t);
        c = p->pick_car(d);
        if (c != nullptr)
        {
            g->add(c);
            t.s = (d==true?tb:cb) + " с парковки занял освободившееся место у " + QString::number(n+1) + " колонки";
            t.d = get_state();
            emit sendResponse(t);
        }
    }
    else
    {
        t.s = "Мы пытались выгнать " + (d==true?tm:cm) + " с " + QString::number(n+1) + " колонки, но оказалось что его там не было";
        t.d = get_state();
        emit sendResponse(t);
    }
    return;
}

State Model::get_state()
{
    State s;
    g->get_cars_state(s.car_gas);
    g->get_trucks_state(s.truck_gas);
    s.parking_car = p->get_num_of_cars();
    s.parking_truck = p->get_num_of_trucks();
    return s;
}








