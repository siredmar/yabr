#include "signal.h"



signal::signal()
{
    PointIndex = 0;
    Min = 10000;
    Max = - 10000;
    NumberOfPoints = 0;
}

void signal::AddPoint(double _x, double _y)
{
    SignalPoints.x.append(double(_x));
    SignalPoints.y.append(double(_y));
    if(_y > Max)
    {
        Max = _y;
    }

    if(_x < Min)
    {
        Min = _x;
    }
    NumberOfPoints++;
    PointIndex++;
}

signal::SignalPointsType signal::GetPointsVector()
{
    return SignalPoints;
}

void signal::ClearPoints()
{
    SignalPoints.x.clear();
    SignalPoints.y.clear();
}

double signal::getMin() const
{
    return Min;
}

double signal::getMax() const
{
    return Max;
}

int signal::getNumberOfPoints() const
{
    return NumberOfPoints;
}
