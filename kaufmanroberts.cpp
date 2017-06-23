#include "kaufmanroberts.h"

KaufmanRoberts::KaufmanRoberts()
{

}

QVector<double> KaufmanRoberts::calculate_qj(int c, const QVector<int> &b, const QVector<int> &t, const QVector<double> &aErl)
{   // the calling routine passes a QVector pointer to this routine
    QVector<double> q;
    int k;

    k = b.size();
    q.resize(c + 1);
    q[0] = 1;

    for (int j = 1; j <= c; j++)
    {
        if (j == 0)
            q[j] = 1;
        else
        {
            q[j] = 0;
            for (int i = 1; i <= k; i++)
            {
                 if (j - b[i - 1] >= 0 && j <= (c - t[i - 1]))
                     q[j] += aErl[i - 1] * b[i - 1] * q[j - b[i - 1]];
            }
        }
        q[j] *= 1 / (double)j;
    }

    return q;
}

QVector<double> KaufmanRoberts::calculate_pj(const QVector<double> &q)
{
    QVector<double> p;
    int c;
    double qs;

    c = q.size() - 1;
    p.resize(c+1);
    qs = calculate_qsum(q);

    for (int i = 0; i <= c; i++)
        p[i] = q[i]/qs;

    return p;
}

QVector<QVector<double> > KaufmanRoberts::calculate_ykj(const QVector<double> &q, const QVector<double> &aErl, const QVector<int> &b, const QVector<int> &t)
{
    QVector<QVector<double> > y;
    int c, k;

    c = q.size() - 1;
    k = b.size();
    y.resize(q.size()); // make y have the same size as q

    for (int j = 0; j <= c; j++)
    {
        y[j].resize(k);
        for (int i = 1; i <= k; i++)
        {
            if (j - b[i - 1] >= 0 && q[j] > 0 && j <= c - t[i - 1])
                y[j][i - 1] = aErl[i - 1] * q[j - b[i - 1]] / q[j];
            else
                y[j][i - 1] = 0;
        }
    }

    return y;
}
QVector<double> KaufmanRoberts::calculate_sum_ykbk(const QVector<int> &b, const QVector<QVector<double> > &y)
{
    QVector<double> sumyb;
    int c, k;

    c = y.size() - 1;
    k = b.size();
    sumyb.resize(y.size());

    for (int j=0; j <= c; j++)
    {
        sumyb[j] = 0;
        for (int i=0; i < k; i++)
            sumyb[j] += b[i] * y[j][i];
    }

    return sumyb;
}

QVector<double> KaufmanRoberts::calculate_pbk(const QVector<double> &q, const QVector<int> &b, const QVector<int> &t)
{   // arguments are passed by reference because they are not going to change
    QVector<double> pb;
    int c, k;
    double qs;

    c = q.size() - 1;
    k = b.size();   // returns the number of items in the vector
    pb.resize(k);
    qs = calculate_qsum(q);

    for (int i = 0; i < k; i++)
    {
        pb[i] = 0;
        for (int j = c - b[i] - t[i] + 1; j <= c; j++)
            if (j >= 0)
                pb[i] += q[j] / qs;
    }

    return pb;
}

QVector<QVector<double> > KaufmanRoberts::calculate_pbArray(const QVector<QVector<double>> &aCalc, const int &c, const QVector<int> &b, const QVector<int> &t)
{
    QVector<QVector<double> > y, pbArray, eArray;
    QVector<double> q, pi, linkUt;
    int k, numOfSteps;

    k = b.size();
    numOfSteps = aCalc.size();
    eArray.resize(numOfSteps);
    linkUt.resize(numOfSteps);
    pbArray.resize(numOfSteps);

    for (int i = 0; i < numOfSteps; i++)
    {
        eArray[i].resize(k);
        pbArray[i].resize(k);
        q = calculate_qj(c, b, t, aCalc[i]);
        y = calculate_ykj(q, aCalc[i], b, t);
        pi = calculate_pj(q);
        eArray[i] = calculate_E(pi, y);
        pbArray[i] = calculate_pbk(q, b, t);
        linkUt[i] = calculateLinkUt(pi);
    }
    this->eArray = eArray;
    this->linkUt = linkUt;

    return pbArray;
}

QVector<QVector<double> > KaufmanRoberts::calculate_pbArrayEngset(const QVector<QVector<double>> &aCalc, const int &c, const QVector<int> &b, const QVector<int> &t, const QVector<int> &nEng)
{
    QVector<QVector<double> > y, aErlEqArray, pbArrayEngset, eArray;
    QVector<double> q, qEng, pi;
    int k, numOfSteps;

    aErlEqArray = create_aErlEqArray(aCalc, nEng);

    k = b.size();
    numOfSteps = aCalc.size();
    eArray.resize(numOfSteps);
    linkUt.resize(numOfSteps);
    pbArrayEngset.resize(numOfSteps);

    for (int i = 0; i < numOfSteps; i++)
    {
        eArray[i].resize(k);
        pbArrayEngset[i].resize(k);
        q = calculate_qj(c, b, t, aErlEqArray[i]);
        y = calculate_ykj(q, aErlEqArray[i], b, t);
        qEng = calculate_qj_Engset(aCalc[i], b, t, nEng, y);
        pi = calculate_pj(qEng);
        eArray[i] = calculate_E(pi, y);
        pbArrayEngset[i] = calculate_pbk(qEng, b, t);
    }

    this->eArray = eArray;
    this->linkUt = linkUt;

    return pbArrayEngset;
}

QVector<QVector<double> > KaufmanRoberts::calculate_pbArrayErlEng(const QVector<QVector<double>> &aCalc, const int &c, const QVector<int> &b, const QVector<int> &t, const QVector<int> &nErlEng, QVector<QString> modelType)
{
    QVector<QVector<double> > y, aErlEngEqArray, pbArrayErlEng, eArray;
    QVector<double> q, qErlEng, pi;
    int k, numOfSteps;

    aErlEngEqArray = create_aErlEngEqArray(aCalc, nErlEng, modelType);

    k = b.size();
    numOfSteps = aCalc.size();
    eArray.resize(numOfSteps);
    linkUt.resize(numOfSteps);
    pbArrayErlEng.resize(numOfSteps);

    for (int i = 0; i < numOfSteps; i++)
    {
        eArray[i].resize(k);
        pbArrayErlEng[i].resize(k);
        q = calculate_qj(c, b, t, aErlEngEqArray[i]);
        y = calculate_ykj(q, aErlEngEqArray[i], b, t);
        qErlEng = calculate_qj_ErlEng(aCalc[i], b, t, nErlEng, y, modelType);
        pi = calculate_pj(qErlEng);
        eArray[i] = calculate_E(pi, y);
        pbArrayErlEng[i] = calculate_pbk(qErlEng, b, t);
    }
    this->eArray = eArray;
    this->linkUt = linkUt;

    return pbArrayErlEng;
}

double KaufmanRoberts::calculate_qsum(const QVector<double> &q)
{
    double qsum;

    qsum = 0;

    for (int i = 0; i < q.size(); i++)
        qsum += q[i];

    return qsum;
}

double KaufmanRoberts::calculateLinkUt(const QVector<double> p)
{
    int c;
    double lu;

    c = p.size() - 1;
    lu = 0;

    for (int j = 1; j <= c; j++)
        lu += j * p[j];

    return lu;
}

double KaufmanRoberts::calculate_c(const QVector<int> &b, const QVector<int> &t, const QVector<double> &aErl, const QVector<double> &pbin)
{
    QVector<double> q, pb;
    bool flag;
    int c, k;

    k = b.size();
    pb.resize(pbin.size()); // make pb have the same size as pbin
    c = 0;
    flag = false;

    while (flag == false)
    {
        flag = true;
        c++;
        q = calculate_qj(c, b, t, aErl);
        pb = calculate_pbk(q, b, t);
        for (int i = 0; i < k; i++)
        {
            if (pb[i] > pbin[i])
                flag = false;
        }
    }

    return c;
}

QVector<double> KaufmanRoberts::calculate_E(const QVector<double> p, const QVector<QVector<double> > y)
{
    QVector<double> e;
    int c, k;

    c = p.size() - 1;
    k = y[0].size();
    e.resize(k);

    for (int n = 0; n < k; n++)
    {
        e[n] = 0;
        for (int j = 0; j <= c; j++)
        {
            if (y[j][n] == y[j][n])
                e[n] += y[j][n] * p[j];
        }
    }

    return e;
}

QVector<double> KaufmanRoberts::calculate_qj_Engset(const QVector<double> &aEng, const QVector<int> &b, const QVector<int> &t, QVector<int> nEng, const QVector<QVector<double> > &y)
{
    QVector<double> q;
    int k, c;

    k = b.size();
    c = y.size() - 1;
    q.resize(c + 1);
    q[0] = 1;

    for (int j = 1; j <= c; j++)
    {
        if (j == 0)
            q[j] = 1;
        else
        {
            q[j] = 0;
            for (int i = 1; i <= k; i++)
            {
                 if (j - b[i - 1] >= 0 && j <= (c - t[i - 1]))
                     if (j - b[i - 1] <= 0)
                        q[j] += (nEng[i - 1]) * aEng[i - 1]*b[i - 1] * q[j - b[i - 1]];
                    else
                         q[j] += (nEng[i - 1] - y[j - b[i - 1]][i - 1]) * aEng[i - 1]*b[i - 1] * q[j - b[i - 1]];
            }
        }
        q[j] *= 1 / (double)j;
    }

    return q;
}

QVector<double> KaufmanRoberts::calculate_qj_ErlEng(const QVector<double> &aErlEng, const QVector<int> &b, const QVector<int> &t, QVector<int> nEng, const QVector<QVector<double>> &y, QVector<QString> &modelType)
{
    QVector<double> q;
    int k, c;

    k = b.size();
    c = y.size() - 1;
    q.resize(c+1);
    q[0] = 1;

    for(int j = 1; j <= c; j++)
    {
        q[j] = 0;
        for(int i = 1; i <= k; i++)
        {
            if (j - b[i - 1] >= 0 && j <= (c - t[i - 1]))
            {
                if (modelType[i - 1] == "Erlang")
                    q[j] += aErlEng[i - 1] * b[i - 1] * q[j - b[i - 1]];
                else if (modelType[i - 1] == "Engset")
                {
                    q[j] += (nEng[i - 1] - y[j - b[i - 1]][i - 1]) * aErlEng[i - 1]*b[i - 1] * q[j - b[i - 1]];
                }
            }
        }
        q[j] *= 1/(double)j;
    }

    return q;
}

double KaufmanRoberts::calculate_C_Engset(const QVector<double> &aEng, const QVector<double> &aErlEq, const QVector<int> &b, const QVector<int> &t, const QVector<int> nEng, const QVector<double> &pbin)
{
    QVector<double> q, qEng, pb;
    QVector<QVector<double> > y;
    bool flag;
    int c, k;

    k = b.size();
    pb.resize(pbin.size()); // make pb have the same size as pbin

    c = 0;
    flag = false;

    while (flag == false)
    {
        flag = true;
        c++;
        q = calculate_qj(c, b, t, aErlEq);
        y = calculate_ykj(q, aErlEq, b, t);
        qEng = calculate_qj_Engset(aEng, b, t, nEng, y);
        pb = calculate_pbk(qEng, b, t);
        for(int i=0; i < k; i++)
        {
            if(pb[i] > pbin[i])
                flag = false;
        }
    }

    return c;
}

double KaufmanRoberts::calculate_C_ErlEng(const QVector<double> &aErlEng, const QVector<double> &aErlEq, const QVector<int> &b, const QVector<int> &t, const QVector<int> nErlEng, const QVector<double> &pbin, QVector<QString> modelType)
{
    QVector<double> q, qErlEng, pb;
    QVector<QVector<double> > y;
    bool flag;
    int c, k;

    k = b.size();
    pb.resize(pbin.size()); // make pb have the same size as pbin

    c = 0;
    flag = false;

    while (flag == false) {
        flag = true;
        c++;
        q = calculate_qj(c, b, t, aErlEq);
        y = calculate_ykj(q, aErlEq, b, t);
        qErlEng = calculate_qj_ErlEng(aErlEng, b, t, nErlEng, y, modelType);
        pb = calculate_pbk(qErlEng, b, t);
        for(int i=0; i<k; i++)
        {
            if(pb[i] > pbin[i])
                flag = false;
        }
    }

    return c;
}

QVector<QVector<double> > KaufmanRoberts::create_aErlEqArray(const QVector<QVector<double> > &aCalc, QVector<int> nEng)
{
    QVector<QVector<double> > aErlEqArray;
    int numOfRows, numOfColumns;

    numOfRows = aCalc.size();
    numOfColumns = aCalc[0].size();
    aErlEqArray.resize(numOfRows);

    for (int i = 0; i < numOfRows ; i++)
    {
        aErlEqArray[i].resize(numOfColumns);
        for (int j = 0; j < numOfColumns ; j++)
            aErlEqArray[i][j] = aCalc[i][j] * nEng[j];
    }

    return aErlEqArray;
}

QVector<QVector<double> > KaufmanRoberts::create_aErlEngEqArray(const QVector<QVector<double>> &aCalc, QVector<int> nErlEng, QVector<QString> modelType)
{
    QVector<QVector<double> > aErlEngEqArray;
    int numOfRows, numOfColumns;

    numOfRows = aCalc.size();
    numOfColumns = aCalc[0].size();
    aErlEngEqArray.resize(numOfRows);

    for (int i = 0; i < numOfRows ; i++)
    {
        aErlEngEqArray[i].resize(numOfColumns);
        for (int j = 0; j < numOfColumns ; j++)
        {
            if (modelType[j] == "Erlang")
                aErlEngEqArray[i][j] = aCalc[i][j];
            else if (modelType[j] == "Engset")
                aErlEngEqArray[i][j] = aCalc[i][j] * nErlEng[j];
        }
    }

    return aErlEngEqArray;
}

QVector<QVector<double>> KaufmanRoberts::return_EArray()
{
    return eArray;
}

QVector<double> KaufmanRoberts::return_linkUt()
{
    return linkUt;
}
