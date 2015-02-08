#include "Space.h"
#include <iostream>

GFA::Space::Space()
    :   dim_(0)
{
}

GFA::Space::Space(const Size dim)
    :   dim_(dim)
{
}

GFA::Size GFA::Space::GetDimension(void) const
{
    return dim_;
}

/*
bool Space::operator!=(const Space &other) const
{
    if ( other.dim != dim )
        return true;
    else
        return false;
}
*/

void GFA::Space::Print(void) const
{
    std::cout << "Space(" << dim_ << ")" << std::endl;
}
