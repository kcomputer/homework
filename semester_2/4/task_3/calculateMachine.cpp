#include "calculateMachine.h"


double calculate(double dOperand1, QString strOperation, double dOperand2)
{
    double  dResult      = 0;

    if (strOperation == "+") {
        dResult = dOperand1 + dOperand2;
    }
    if (strOperation == "-") {
        dResult = dOperand1 - dOperand2;
    }
    if (strOperation == "/") {
        dResult = dOperand1 / dOperand2;
    }
    if (strOperation == "*") {
        dResult = dOperand1 * dOperand2;
    }
    return dResult;
}
