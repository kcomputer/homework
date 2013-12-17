#include "computer.h"


void Computer::virus()
{
    int currentVirusProbability = this->probabilityGenerator->getRandomNumber() % 101;

    if (currentVirusProbability > this->operatingSystem->getVirusProbability())
    {
        this->isInfectedMV = true;
    }
}
bool Computer::isInfected()
{
    return this->isInfectedMV;
}


