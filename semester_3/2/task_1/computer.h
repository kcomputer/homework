#ifndef COMPUTER_H
#define COMPUTER_H
#include "randomNumberGenerator.h"
#include "os.h"
#include "time.h"

//! A class that represents a computer with its OS, infection state and probabilty of getting infected
class Computer
{
public:
    Computer(OS* operatingSystem, bool state, RandomNumberGeneratorInterface *probabilityGenerator){
     this->operatingSystem = operatingSystem;
     this->isInfectedMV = state;
     this->probabilityGenerator = probabilityGenerator;
    }
    void virus();
    bool isInfected();
private:
    OS* operatingSystem;
    bool isInfectedMV;
    RandomNumberGeneratorInterface* probabilityGenerator;
};

#endif // COMPUTER_H
