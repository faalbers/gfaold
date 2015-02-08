#include "Color.h"
#include <iostream>

GFA::Color::Color()
    : Tuple(4)
{
    dataPtr_[3] = 1.0;
}

GFA::Color::Color(const Scalar r, const Scalar g, const Scalar b, const Scalar a)
    : Tuple(4)
{
    dataPtr_[0] = r;
    dataPtr_[1] = g;
    dataPtr_[2] = b;
    dataPtr_[3] = a;
}

void GFA::Color::Print(void) const
{
    std::cout << "Color(";
    for ( Index c = 0; c < cols_; c++ )
        if ( c == 0 )
            std::cout << dataPtr_[c];
        else
            std::cout << ", " << dataPtr_[c];
    std::cout << ")" << std::endl;
    std::cout << std::endl;
}


