#ifndef SIGNAL_H
#define SIGNAL_H

#include "QVector"

class signal
{
    public:
        typedef struct
        {
                 QVector<double> x;
                 QVector<double> y;
        } SignalPointsType;

        SignalPointsType SignalPoints;

        int NumberOfPoints;
        signal();
        SignalPointsType GetPointsVector();
        void AddPoint(double _x, double _y);
        void ClearPoints();
        double getMin() const;
        double getMax() const;
        int getNumberOfPoints() const;

    private:
        int PointIndex;
        double Min;
        double Max;
};

#endif // SIGNAL_H
