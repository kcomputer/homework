#include "vector.h"

Vector::Vector(int* valuesArray, int nSize)
{
    size = nSize;
    values = new int[size];
    for(int i = 0; i < size; i++)
           values[i] = valuesArray[i];
}

Vector::Vector(const Vector &vector)
{
    size = vector.size;
    values = new int[size];
    for(int i = 0; i < size; i++)
           values[i] = vector.values[i];
}

Vector::~Vector()
{
    delete[] values;
}

int* Vector::getValues()
{
    return this->values;
}

bool Vector::isNull()
{
    for(int i = 0; i < size; i++)
    {
        if (values[i] != 0)
            return false;
    }
    return true;
}

Vector Vector::operator+(const Vector &rightVector)
{
    if (this->size != rightVector.size)
        throw Vector::VectorsMismatch();
    Vector result(*this);
    for(int i = 0; i < size; i++)
        result.values[i] += rightVector.values[i];
    return result;
}

Vector Vector::operator-(const Vector &rightVector)
{
    if (this->size != rightVector.size)
        throw Vector::VectorsMismatch();
    Vector result(*this);
    for(int i = 0; i < size; i++)
        result.values[i] -= rightVector.values[i];
    return result;
}

Vector Vector::operator=(const Vector &rightVector)
{
    delete[] values;
    size = rightVector.size;
    values = new int[size];
    for(int i = 0; i < size; i++)
        this->values[i] = rightVector.values[i];
    return *this;
}

int Vector::scalarMultiplication(Vector &rightVector)
{
    int result = 0;
    for(int i = 0; i < size; i++)
        result = result + values[i] * rightVector.values[i];
    return result;
}
