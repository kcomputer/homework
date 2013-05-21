#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>
#include "sort.h"
#include <iostream>
#include "comparer.h"



class SortTest : public QObject
{
    Q_OBJECT
public:
    explicit SortTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        charArray = new char[3];
        charArray[0] = 'A';
        charArray[1] = 'B';
        charArray[2] = 'C';

        intArray = new int[3];
        doubleArray = new double[3];
        double temp = 5.5;
        for (int i = 0; i < 3; ++i)
        {
            intArray[i] = i + 1;
            doubleArray[i] = temp + i;
        }
        intArraySorter = new Sort<int>();
        doubleArraySorter = new Sort<double>();

    }
    void cleanup()
    {
        delete[] charArray;
        delete[] intArray;
        delete[] doubleArray;
        delete intArraySorter;
        delete doubleArraySorter;
    }

    void charArraySorterTest()
    {
        charArraySorter->makeSort(charArray, 3, charCompare);
        QVERIFY (charArray[0] == 'C');
    }

    void intArraySorterTest()
    {
        intArraySorter->makeSort(intArray, 3, intCompare);
        QVERIFY (intArray[0] == 3);
    }
    void doubleArraySorterTest()
    {
        doubleArraySorter->makeSort(doubleArray, 3, doubleCompare);
        QVERIFY (doubleArray[0] == 7.5);
    }

private:
    int *intArray;
    Sort<int> *intArraySorter;
    Comparer<int> intCompare;

    double *doubleArray;
    Sort<double> *doubleArraySorter;
    Comparer<double> doubleCompare;
    double temp;

    char *charArray;
    Sort<char> *charArraySorter;
    Comparer<char> charCompare;
};

