#ifndef LINEPAINTER_H
#define LINEPAINTER_H

#include <QPainter>
#include <QWidget>
#include "qcustomplot.h"
#include "signal.h"

class Linepainter : public QWidget
{
    public:
        int LineIndex;
        Linepainter();
        void PaintLine(QCustomPlot *plotarea, signal sig, int channel);
        void Clear(QCustomPlot *plotarea);

        int getLineIndex() const;
        void setLineIndex(int value);
};
#endif // LINEPAINTER_H
