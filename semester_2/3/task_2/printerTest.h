#ifndef PRINTERTEST_H
#define PRINTERTEST_H


#include <QTest>
#include <QObject>
#include "spiralPrinter.h"
#include "fileSpiralPrinter.h"
#include "consoleSpiralPrinter.h"
#include <sstream>


//! Testing sorter.



class PrinterTest : public QObject
{
    Q_OBJECT
public:
    explicit PrinterTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        mArray = new int*[4];
        for (int i = 0; i < 4; ++i)
        {
             mArray[i] = new int[4];
        }
        for (int i = 1; i < 4; i++)
        {
            for (int j = 1; j < 4; ++j)
            {
                mArray[i][j] = i + j ;
            }
        }
    }
    void cleanup()
    {

        delete mPrinter;
        for (int i = 0; i < 4; ++i)
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
        QVERIFY(n == 1);

        QVERIFY(!nOut.str().compare("5 4 7 8 9 6 3 2 1"));
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
