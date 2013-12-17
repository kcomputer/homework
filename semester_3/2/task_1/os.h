#ifndef OS_H
#define OS_H

//! Base class for different operating systems

class OS
{
public:
    int getVirusProbability()
    {
        return virusProbability;
    }
protected:
    int virusProbability;

};

#endif // OS_H
