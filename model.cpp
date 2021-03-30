#include "model.h"

State Model::DefaultState = {false,false,false,false,false,0,0};

Model::Model() : QObject()
{
    reset();
}

void Model::reset()
{
    Response t;
    state = DefaultState;
    t.d = state;
    t.s = "Протокол 'Чистый Лист'";

    emit sendResponse(t);
}

void Model::request()
{
    Response t;
    t.d = state;
    t.is_text = false;

    emit sendResponse(t);
}

int Model::freePlaces()
{
    return MAX_P-state.parking_car-state.parking_truck*2;
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
    Response t;
    if(d)
    {
        if (!state.truck_gas[0])
        {
            state.truck_gas[0]=true;
            t.s = "На заправку приезжает грузовик и сразу отправляется на 1 колонку";
        }
        else if (!state.truck_gas[1])
        {
            state.truck_gas[1]=true;
            t.s = "На заправку приезжает грузовик и сразу отправляется на 2 колонку";
        }
        else if (freePlaces()>=2)
        {
            state.parking_truck++;
            t.s = "На заправку приезжает грузовик, но колонки заняты и он встает на парковку";
        }
        else
        {
            t.s = "На заправку приезжает грузовик, но колонки и парковка заняты и ему приходится ехать дальше";
        }
    }
    else
    {
        if (!state.car_gas[0])
        {
            state.car_gas[0]=true;
            t.s = "На заправку приезжает автомобиль и сразу отправляется на 1 колонку";
        }
        else if (!state.car_gas[1])
        {
            state.car_gas[1]=true;
            t.s = "На заправку приезжает автомобиль и сразу отправляется на 2 колонку";
        }
        else if (!state.car_gas[2])
        {
            state.car_gas[2]=true;
            t.s = "На заправку приезжает автомобиль и сразу отправляется на 3 колонку";
        }
        else if (freePlaces()>=1)
        {
            state.parking_car++;
            t.s = "На заправку приезжает автомобиль, но колонки заняты и он встает на парковку";
        }
        else
        {
            t.s = "На заправку приезжает автомобиль, но колонки и парковка заняты и ему приходится ехать дальше";
        }
    }

    t.d=state;
    emit sendResponse(t);
    return;
}

void Model::release(bool d, short n)
{
    Response t;
    if(d)
    {
        if (state.truck_gas[n])
        {
            state.truck_gas[n] = false;
            t.d = state;
            t.s = "Грузовик на " + QString::number(n+1) + " колонке заправился и уехал с заправки";
            emit sendResponse(t);

            if (state.parking_truck>0)
            {
                state.parking_truck--;
                state.truck_gas[n] = true;
                t.d = state;
                t.s = "Грузовик с парковки занял освободившееся место у " + QString::number(n+1) + " колонки";
                emit sendResponse(t);
            }
        }
        else
        {
            t.d = state;
            t.s = "Мы пытались выгнать грузовик с " + QString::number(n+1) + " колонки, но оказалось что его там не было";
            emit sendResponse(t);
        }
    }
    else
    {
        if (state.car_gas[n])
        {
            state.car_gas[n] = false;
            t.d = state;
            t.s = "Автомобиль на " + QString::number(n+1) + " колонке заправился и уехал с заправки";
            emit sendResponse(t);

            if (state.parking_car>0)
            {
                state.parking_car--;
                state.car_gas[n] = true;
                t.d = state;
                t.s = "Автомобиль с парковки занял освободившееся место у " + QString::number(n+1) + " колонки";
                emit sendResponse(t);
            }
        }
        else
        {
            t.d = state;
            t.s = "Мы пытались выгнать Автомобиль с " + QString::number(n+1) + " колонки, но оказалось что его там не было";
            emit sendResponse(t);
        }
    }
    return;
}












