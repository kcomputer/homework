#ifndef COMPARER_H
#define COMPARER_H


//! Comparer class interface
template <class T>
class Comparer
{
public:
    //! Returns true if left value is less than right
    bool operator()(const T& leftValue, const T& rigthValue )
    {
        if (leftValue < rigthValue)
            return true;
        return false;
    }
};

#endif // COMPARER_H
