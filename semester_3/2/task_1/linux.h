#ifndef LINUX_H
#define LINUX_H
#include "os.h"

class Linux : public OS
{
public:
    Linux()
    {
        virusProbability = 10;
    }
};

#endif // LINUX_H
