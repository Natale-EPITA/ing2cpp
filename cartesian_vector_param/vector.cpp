#include <iostream>
#include <ostream>




#include "vector.h"


Vector::Vector()
{
    size = NDIM;
    for(size_t i = 0;i < size; i++)
        data[i] = 0;
}

Vector::Vector(std::initializer_list<value> x)
{
    size = x.size();
    int i = 0;
    for(auto & tmp : x)
    {
        data[i++] = tmp;
    }
}

size_t Vector::getSize() const
{
    return size;
}

Vector& Vector::operator+=(const Vector& second)
{
    for (int i = 0; i < second.getSize(); i++)
    {
        data[i] += second[i];
    }
    return *this;
}



Vector& Vector::operator-=(const Vector& second)
{
    for (int i = 0; i < second.getSize(); i++)
    {
        data[i] -= second[i];
    }
    return *this;
}

Vector Vector::operator+(const Vector& second)
{
    auto v = Vector();
    for (int i = 0; i < second.getSize(); i++)
    {
        v[i] = second[i] + (*this)[i];
    }
    return v;
}

Vector Vector::operator-(const Vector& second)
{
    auto v = Vector();
    for (int i = 0; i < second.getSize(); i++)
    {
        v[i] = second[i] - (*this)[i];
    }
    return v;
}

value Vector::operator*(const Vector& second)
{
    value v = 0;
    for (int i = 0; i < second.getSize(); i++)
    {
        v += second[i] * (*this)[i];
    }
    return v;
}

Vector operator*(Vector& second,const value val)
{
    auto v = Vector();
    for (int i = 0; i < second.getSize(); i++)
    {
        v[i] = second[i] * val;
    }
    return v;
}

Vector operator*=(Vector& second, const value a)
{
    for (int i = 0; i < second.getSize(); i++)
    {
        second[i] *= a;
    }
    return second;
}






Vector operator+=(Vector& second, const value a)
{
    for (int i = 0; i < second.getSize(); i++)
    {
        second[i] += a;
    }
    return second;
}

Vector operator+=(Vector& second, const value a)
{
    for (int i = 0; i < second.getSize(); i++)
    {
        second[i] += a;
    }
    return second;
}

value Vector::operator[](size_t i) const
{
    return data[i];
}





std::ostream& operator<<(std::ostream &os, const Vector& second)
{
    os << "{";
    for (int i = 0; i < second.getSize(); i++)
    {
        os << second[i] << (i == second.getSize() - 1 ? "" : ",");
    }
    return os << "}";
}
