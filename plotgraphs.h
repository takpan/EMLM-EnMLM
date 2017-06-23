#ifndef PLOTGRAPHS_H
#define PLOTGRAPHS_H

#include "qcustomplot.h"


class PlotGraphs : public QCustomPlot
{
public:
    explicit PlotGraphs(QWidget *parent);

    void createGraph(QVector<QVector<double>> pbOut, QVector<QString> colorList);

    void createUGraph(const QVector<double> &linkUt);
};

#endif // PLOTGRAPHS_H
