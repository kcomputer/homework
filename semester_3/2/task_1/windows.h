#ifndef WINDOWS_H
#define WINDOWS_H


#include "os.h"
class Windows : public OS
{
public:
    Windows()
    {
        virusProbability = 60;
    }
};

#endif // WINDOWS_H
