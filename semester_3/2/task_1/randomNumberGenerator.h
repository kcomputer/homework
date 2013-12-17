#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

//! A concrete class
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "randomNumberGeneratorInterface.h"


//! A class that generates a random number.

class RandomNumberGenerator : public RandomNumberGeneratorInterface
{
public:
    int getRandomNumber()
    {
        int numberToReturn = 0;
        srand (time(NULL));

        numberToReturn = rand();

        return (numberToReturn);
    }
};


#endif // RANDOMNUMBERGENERATOR_H
