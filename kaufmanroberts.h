#ifndef KAUFMANROBERTS_H
#define KAUFMANROBERTS_H

#include <QVector>
//#include <QSize>
//#include <QtAlgorithms>


class KaufmanRoberts
{
public:
    KaufmanRoberts();

    QVector<double> calculate_qj(int c, const QVector<int> &b, const QVector<int> &t, const QVector<double> &aErl);

    QVector<double> calculate_qj_Engset(const QVector<double> &aEng, const QVector<int> &b, const QVector<int> &t, QVector<int> nEng, const QVector<QVector<double>> &yk);

    QVector<double> calculate_qj_ErlEng(const QVector<double> &aErlEng, const QVector<int> &b, const QVector<int> &t, QVector<int> nEng, const QVector<QVector<double>> &yk, QVector<QString> &modelType);

    QVector<double> calculate_pj(const QVector<double> &q);

    QVector<QVector<double>> calculate_ykj(const QVector<double> &q, const QVector<double> &aErl, const QVector<int> &b, const QVector<int> &t);

    QVector<double> calculate_pbk(const QVector<double> &q, const QVector<int> &b, const QVector<int> &t);

    QVector<double> calculate_pbk_Engset();

    QVector<QVector<double>> calculate_pbArray(const QVector<QVector<double>> &aCalc, const int &c, const QVector<int> &b, const QVector<int> &t);

    QVector<QVector<double>> calculate_pbArrayEngset(const QVector<QVector<double>> &aCalc, const int &c, const QVector<int> &b, const QVector<int> &t, const QVector<int> &nEng);

    QVector<QVector<double>> calculate_pbArrayErlEng(const QVector<QVector<double>> &aCalc, const int &c, const QVector<int> &b, const QVector<int> &t, const QVector<int> &nErlEng, QVector<QString> modelType);

    double calculate_qsum(const QVector<double> &q);

    double calculateLinkUt(const QVector<double> p);

    QVector<double> calculate_sum_ykbk(const QVector<int> &b, const QVector<QVector<double>> &y);

    double calculate_c(const QVector<int> &b, const QVector<int> &t, const QVector<double> &aErl, const QVector<double> &pbin);

    double calculate_C_Engset(const QVector<double> &aEng, const QVector<double> &aErlEq, const QVector<int> &b, const QVector<int> &t, const QVector<int> nEng, const QVector<double> &pbin);

    double calculate_C_ErlEng(const QVector<double> &aErlEng, const QVector<double> &aErlEq, const QVector<int> &b, const QVector<int> &t, const QVector<int> nErlEng, const QVector<double> &pbin, QVector<QString> modelType);

    QVector<double> calculate_E(const QVector<double> p, const QVector<QVector<double>> y);

    QVector<QVector<double>> create_aErlEqArray(const QVector<QVector<double>> &aCalc, QVector<int> nEng);

    QVector<QVector<double>> create_aErlEngEqArray(const QVector<QVector<double>> &aCalc, QVector<int> nErlEng, QVector<QString> modelType);

    QVector<QVector<double>> return_EArray();

    QVector<double> return_linkUt();

private:
    double qs;
    QVector<int> d;
    QVector<double> linkUt;
    QVector<QVector<double>> eArray;
};

#endif // KAUFMANROBERTS_H
