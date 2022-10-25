#include <iostream>
#include <ostream>

#include "config.h"
#include "vector.hh"

Vector::Vector(size_t N)
{
    vector_size = N;

    data = std::make_unique<value[]>(vector_size);

    for (size_t i = 0; i < vector_size; ++i)
    {
        data[i] = 0;
    }
}

Vector::Vector(std::initializer_list<value> l)
{
    vector_size = l.size();
    std::initializer_list<value>::iterator it;

    data = std::make_unique<value[]>(vector_size);
    size_t i = 0;
    for (it = l.begin(); it != l.end(); ++it)
    {
        data[i++] = *it;
    }
}

Vector::Vector(const Vector &vect)
{
    this->data = std::make_unique<value[]>(vect.size());
    vector_size = vect.size();
    for (size_t i = 0; i < vector_size; ++i)
    {
        data[i] = vect[i];
    }
}

Vector &Vector::operator=(const Vector &v)
{
    this->data = std::make_unique<value[]>(v.size());
    vector_size = v.size();
    for (size_t i = 0; i < v.size(); ++i)
    {
        data[i] = v[i];
    }
    return *this;
}

size_t Vector::size() const
{
    return vector_size;
}

std::ostream &operator<<(std::ostream &o, const Vector &v)
{
    size_t size = v.size();
    o << "{";
    for (size_t i = 0; i < size; ++i)
    {
        o << v[i] << (i == size - 1 ? "" : ",");
    }
    return o << "}";
}

Vector &Vector::operator+=(const Vector &rhs)
{
    for (size_t i = 0; i < vector_size; ++i)
    {
        data[i] += rhs[i];
    }

    return *this;
}


Vector &Vector::operator-=(const Vector &rhs)
{
    for (size_t i = 0; i < vector_size; ++i)
    {
        data[i] -= rhs[i];
    }

    return *this;
}


Vector &Vector::operator+=(value v)
{
    for (size_t i = 0; i < vector_size; ++i)
    {
        data[i] += v;
    }
    return *this;
}


Vector &Vector::operator*=(value v)
{
    for (size_t i = 0; i < vector_size; ++i)
    {
        data[i] *= v;
    }
    return *this;
}


Vector Vector::operator+(const Vector &rhs) const
{
    auto v = Vector(vector_size);
    for (size_t i = 0; i < vector_size; ++i)
    {
        v[i] = data[i] + rhs[i];
    }
    return v;
}


Vector Vector::operator+(value v) const
{
    auto vect = Vector(vector_size);
    for (size_t i = 0; i < vector_size; ++i)
    {
        vect[i] = data[i] + v;
    }
    return vect;
}
value Vector::operator*(const Vector &rhs) const
{
    value product = 0;
    for (size_t i = 0; i < vector_size; ++i)
    {
        product += data[i] * rhs[i];
    }
    return product;
}
Vector Vector::operator*(value v) const
{
    auto vect = Vector(vector_size);
    for (size_t i = 0; i < vector_size; ++i)
    {
        vect[i] = data[i] * v;
    }

    return vect;
}

value &Vector::operator[](size_t idx)
{
    return data[idx];
}

value Vector::operator[](size_t idx) const
{
    return data[idx];
}

Vector operator+(const value &s, const Vector &v)
{
    auto vect = Vector(v.size());
    for (size_t i = 0; i < v.size(); ++i)
    {
        vect[i] = v[i] * s;
    }
    return vect;
}
Vector operator*(const value &s, const Vector &v)
{
    auto vect = Vector(v.size());
    for (size_t i = 0; i < v.size(); ++i)
    {
        vect[i] = v[i] + s;
    }
    return vect;
}
