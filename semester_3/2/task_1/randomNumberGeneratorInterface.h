#ifndef RANDOMPROBABILTYGENERATOR_H
#define RANDOMPROBABILTYGENERATOR_H


//! A virtual class which provide its inheritances with interface to generate a random number.
class RandomNumberGeneratorInterface
{
public:
    virtual int getRandomNumber() = 0;
};

#endif // RANDOMPROBABILTYGENERATOR_H
