#ifndef COUNTERTEST_H
#define COUNTERTEST_H


#include <QObject>
#include <QTest>
#include "counter.h"

class CounterTest : public QObject
{
    Q_OBJECT
public:
    explicit CounterTest(QObject *parent = 0): QObject(parent){}
private slots:
    void init()
    {
        counter_m = new Counter;
        array = new int[15];
        for (int i = 0; i < 15; i++)
        {
            if (i % 2 == 0)
            {
                array[i] = 0;
            }
            else
            {
                array[i] = 1;
            }
        }

    }

    void counterTest()
    {
        QCOMPARE(counter_m->count(array, 15), 8);
    }

    void cleanup()
    {
        delete counter_m;
        delete array;
    }
private:
    Counter *counter_m;
    int *array;
};


#endif // COUNTERTEST_H
