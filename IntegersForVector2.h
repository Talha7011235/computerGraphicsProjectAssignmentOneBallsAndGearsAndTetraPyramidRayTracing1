// IntegersForVector2.h
#ifndef INTEGERSFORVECTOR2_H
#define INTEGERSFORVECTOR2_H

#include <iostream>

struct IntegersForVector2
{
public:
    IntegersForVector2();
    IntegersForVector2(int, int);

    friend std::istream& operator>> (std::istream& in, IntegersForVector2& value);

    int getX() const;
    int getY() const;

private:
    int x;
    int y;
};

#endif
