#include "plotgraphs.h"

PlotGraphs::PlotGraphs(QWidget *parent):
    QCustomPlot(parent)
{
    this->xAxis->setLabel("Step");
    this->yAxis->setLabel("Blocking probability");
    this->xAxis->setAutoTickStep(false);
    this->xAxis->setTickStep(1);
}

void PlotGraphs::createGraph(QVector<QVector<double>> pbOut, QVector<QString> colorList)
{
    QVector<double> x;
    QVector<QVector<double>> y;
    QColor baseColor;
    int xItems, k;

    xItems = pbOut.size();
    k = pbOut[0].size();
    x.resize(xItems);
    y.resize(xItems);

    for (int i = 0; i < xItems; i++)
    {
        addGraph();
        x[i] = i;
    }

    for (int i = 0; i < k; i++)
    {
        y[i].resize(xItems);
        for (int j = 0; j < xItems; j++)
            y[i][j] = pbOut[j][i];
    }

    for (int i = 0; i < k; i++)
    {
        graph(i)->setData(x, y[i]);
        if (i < colorList.size())
            baseColor.setNamedColor(colorList[i]);
        else
            baseColor.setNamedColor("#494949");

        graph(i)->setPen(QPen(baseColor));
        graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, QPen(baseColor, 1), QBrush(baseColor), 6));
        //graph(i)->rescaleAxes();
    }

    QObject::connect(this->xAxis, SIGNAL(rangeChanged(QCPRange)), this->xAxis2, SLOT(setRange(QCPRange)));
    QObject::connect(this->yAxis, SIGNAL(rangeChanged(QCPRange)), this->yAxis2, SLOT(setRange(QCPRange)));
    setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    this->rescaleAxes();
    replot();

}

void PlotGraphs::createUGraph(const QVector<double> &linkUt)
{
    QVector<double> x, y;
    int xItems;

    xItems = linkUt.size();
    x.resize(xItems);
    y.resize(xItems);
    clearGraphs();
    addGraph();

    for (int i = 0; i < xItems; i++)
    {
        x[i] = i;
        y[i] = linkUt[i];
    }

    graph(0)->setData(x, y);
    graph(0)->setPen(QPen(Qt::gray));
    graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, QPen(Qt::gray, 1), QBrush(Qt::gray), 6));

    QObject::connect(this->xAxis, SIGNAL(rangeChanged(QCPRange)), this->xAxis2, SLOT(setRange(QCPRange)));
    QObject::connect(this->yAxis, SIGNAL(rangeChanged(QCPRange)), this->yAxis2, SLOT(setRange(QCPRange)));
    setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    this->rescaleAxes();
    replot();
}

