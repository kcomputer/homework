#ifndef VECTORTEST_H
#define VECTORTEST_H


#include <QtCore/QObject>
#include <QtTest/QTest>
#include "vector.h"

using namespace std;

class VectorTest : public QObject
{
    Q_OBJECT
public:
    explicit VectorTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        size = 10;
        values = new int[size];
        for (int i = 0; i < size; i++)
            values[i] = i;
        mVector = new Vector(values, size);
        mVector2 = new Vector(*mVector);
        for (int i = 0; i < size; i++)
            values[i] = 0;
        mVector3 = new Vector(values, size);
        mVector4 = new Vector(values, size - 1);
    }
    void cleanup()
    {
        delete[] values;
        delete mVector;
        delete mVector2;
        delete mVector3;
        delete mVector4;
    }
    void isNullTest()
    {
        QVERIFY (mVector3->isNull());
    }
    void additionSubtractionTest()
    {
        (*mVector) = (*mVector) + (*mVector2);
        values = mVector->getValues();
        QVERIFY (values[9] == 18);
        (*mVector) = (*mVector) - (*mVector2);
        QVERIFY (values[9] == 9);
    }
    void scalarMultiplicationTest()
    {
        QVERIFY(mVector->scalarMultiplication(*mVector2) == 285);
    }
    void exeptionTest()
    {
        try
        {
           (*mVector) = (*mVector) + (*mVector4);
        }
        catch (Vector::VectorsMismatch)
        {
            QWARN ("Vectors mismatch!");
        }
    }

private:
    Vector* mVector;
    Vector* mVector2;
    Vector* mVector3;
    Vector* mVector4;
    int* values;
    int size;
};
#endif // VECTORTEST_H
