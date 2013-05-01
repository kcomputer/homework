#ifndef CALCULATORTEST_H
#define CALCULATORTEST_H

#include <QTest>
#include <QObject>
#include <calculateMachine.h>


//! Testing calculator.


class CalculatorTest : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void test()
    {
        dOperand1 = 12.5;
        strOperation = "+";
        dOperand2 = 0.5;
        QVERIFY (calculate(dOperand1, strOperation, dOperand2) == (dOperand1 + dOperand2));
    }

private:
    double dOperand1;
    QString strOperation;
    double dOperand2;
};
#endif // CALCULATORTEST_H



