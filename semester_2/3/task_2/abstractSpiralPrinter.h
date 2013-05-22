#ifndef ABSTRACTSPIRALPRINTER_H
#define ABSTRACTSPIRALPRINTER_H

//! Abstract spiral printer.
class AbstractSpiralPrinter
{
public:
    //! Prints elements of a 2d array in spiral way.
    virtual void printer(int ** array, int size) = 0;

    //! Prints integer
    virtual void print(int element) = 0;
};


#endif // ABSTRACTSPIRALPRINTER_H
