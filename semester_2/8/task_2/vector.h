#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>

//! Vector class interface.
class Vector
{
public:

    //! Is throwed when two vectors are not of the same size
    class VectorsMismatch{};

    //! Vector counstructor
    Vector(int* valuesArray, int nSize);

    //! Copy vector constructor
    Vector(const Vector &vector);

    //! Vector destructor.
    ~Vector();

    //! Return array of values.
    int* getValues();

    //! Checks if it is a null
    bool isNull();

    //! Addition for vectors
    Vector operator+(const Vector &rightVector);

    //! Subtraction for vectors
    Vector operator-(const Vector &rightVector);

    //! Assignment operator
    Vector operator=(const Vector &rightVector);

    //! Scalar multiplication of vectors
    int scalarMultiplication(Vector &rightVector);

private:
    int* values;
    int size;
};
#endif // VECTOR_H
