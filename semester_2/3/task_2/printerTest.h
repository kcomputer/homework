#ifndef PRINTERTEST_H
#define PRINTERTEST_H


#include <QTest>
#include <QObject>
#include "spiralPrinter.h"
#include "fileSpiralPrinter.h"
#include "consoleSpiralPrinter.h"
#include <sstream>
#include <iostream>

using namespace std;


//! Testing sorter.



class PrinterTest : public QObject
{
    Q_OBJECT
public:
    explicit PrinterTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        mArray = new int*[3];
        for (int i = 0; i < 3; ++i)
        {
             mArray[i] = new int[3];
        }
        int temp = 1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; ++j)
            {
                mArray[i][j] = temp ;
                ++temp;
            }
        }
    }
    void cleanup()
    {
        delete mPrinter;
        for (int i = 0; i < 3; ++i)
        {
            delete[] mArray[i];
        }
        delete [] mArray;
    }

    void testPrinter()
    {
        streambuf* buff = cout.rdbuf();
        cout.rdbuf(nOut.rdbuf());


        mPrinter = new ConsoleSpiralPrinter();
        mPrinter->printer(mArray, 3);

        QVERIFY(!nOut.str().compare("5 4 7 8 9 6 3 2 1 "));
        cout.clear();
        cout.rdbuf(buff);
    }

private:
    int n;
    AbstractSpiralPrinter *mPrinter;
    int** mArray;
    stringstream nOut;
};


#endif // PRINTERTEST_H
