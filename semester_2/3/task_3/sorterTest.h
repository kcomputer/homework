#ifndef SORTERTEST_H
#define SORTERTEST_H

#include <QTest>
#include <QObject>
#include "sort.h"
#include "qSort.h"
#include "bubbleSort.h"

//! Testing sorter.



class SortTest : public QObject
{
    Q_OBJECT
public:
    explicit SortTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        mArray = new int*[1];
        mArray[0] = new int[4];
        n = 4;
        for (int i = 0; i < 4; i++)
        {
           mArray[0][i] = n ;
           --n;
        }
    }
    void cleanup()
    {
        delete [] mArray[0];
        delete mSorter;
        delete [] mArray;
    }

    void testQSorter()
    {
        mSorter = new QuickSort();
        mSorter->makeSort(mArray, 1, 4);
        n = 1;
        for (int i = 0; i < 4; i++)
        {
            QVERIFY(mArray[0][i] == n);
            ++n;
        }
    }

    void testBubbleSorter()
    {
        mSorter = new BubbleSort();
        mSorter->makeSort(mArray, 1, 4);
        n = 1;
        for (int i = 0; i < 4; i++)
        {
            QVERIFY(mArray[0][i] == n);
            ++n;
        }
    }


private:
    int n;
    Sort* mSorter;
    int** mArray;
};

#endif // SORTERTEST_H
