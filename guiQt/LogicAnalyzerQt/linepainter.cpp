#include "linepainter.h"
#include "signal.h"

Linepainter::Linepainter()
{

}

void Linepainter::PaintLine(QCustomPlot *plotarea, signal sig, int channel)
{
    signal::SignalPointsType linePoints = sig.GetPointsVector();

    // create graph and assign data to it:
//    plotarea->clearGraphs();
    plotarea->addGraph();
    plotarea->graph(channel)->setData(linePoints.x, linePoints.y);
    if(sig.getNumberOfPoints() % 100 == 0)
    {
        // give the axes some labels:
        plotarea->xAxis->setLabel("x");
        plotarea->yAxis->setLabel("y");
        // set axes ranges, so we see all data:
//        plotarea->xAxis->setRange(0, sig.getNumberOfPoints());
        plotarea->xAxis->setRange(0, 10000);
        plotarea->yAxis->setRange(-0.1, 9.5);

        plotarea->replot();
    }

}

void Linepainter::Clear(QCustomPlot *plotarea)
{
    plotarea->removeGraph(0);
    plotarea->replot();
}

int Linepainter::getLineIndex() const
{
    return LineIndex;
}

void Linepainter::setLineIndex(int value)
{
    LineIndex = value;
}
