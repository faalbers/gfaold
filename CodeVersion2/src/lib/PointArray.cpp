#include "PointArray.h"
//==============================================================================
GFA::PointArray::PointArray(const Size &dim, const Size &size)
    :   dataPtr_(new Scalar[(dim+1)*size]),
        dim_(dim),
        size_(size)
{
}
//==============================================================================
GFA::PointArray::~PointArray()
{
   delete[] dataPtr_;
}
//==============================================================================
const GFA::Size & GFA::PointArray::dim() const
{
    return dim_;
}
//==============================================================================
const GFA::Size & GFA::PointArray::size() const
{
    return size_;
}
//==============================================================================
