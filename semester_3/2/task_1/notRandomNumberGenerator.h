#ifndef NOTRANDOMNUMBERGENERATOR_H
#define NOTRANDOMNUMBERGENERATOR_H

#include "randomNumberGeneratorInterface.h"

//! A class that always return 100. It's used for tests.

class NotRandomNumberGenerator : public RandomNumberGeneratorInterface
{
public:
    int getRandomNumber()
    {
        return 100;
    }
};


#endif // NOTRANDOMNUMBERGENERATOR_H
