#ifndef SORTTEST_H
#define SORTTEST_H



#include <QtCore/QObject>
#include <QtTest/QTest>
#include "sort.h"
#include "bubbleSort.h"
#include "heapSort.h"
#include "qSort.h"

#include <iostream>

using namespace std;


class SortTest : public QObject
{
    Q_OBJECT
public:
    explicit SortTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        array = new int[15];
        for (int i = 0; i < 14; ++i)
        {
            array[i] = 100 - i;
        }
        sorter = new QSort();
        sorter2 = new HeapSort();
        sorter3 = new BubbleSort();
    }
    void cleanup()
    {
        delete[] array;
        delete sorter;
        delete sorter2;
        delete sorter3;
    }

    void testQSort()
    {
        sorter->makeSort(array, 14);
        QVERIFY (array[1] == 88);
    }
    void testHeapSort()
    {
        sorter2->makeSort(array, 14);
        QVERIFY (array[1] == 88);
    }
    void testBubbleSort()
    {
        sorter3->makeSort(array, 14);
        QVERIFY (array[1] == 88);
    }

private:
    int *array;
    Sort *sorter;
    Sort *sorter2;
    Sort *sorter3;
};
QTEST_MAIN(SortTest)
#endif // SORTTEST_H
