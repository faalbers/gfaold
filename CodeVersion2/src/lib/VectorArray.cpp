#include "VectorArray.h"
//==============================================================================
GFA::VectorArray::VectorArray(const Size &dim, const Size &size)
    :   dataPtr_(new Scalar[(dim+1)*size]),
        dim_(dim),
        size_(size)
{
}
//==============================================================================
GFA::VectorArray::~VectorArray()
{
   delete[] dataPtr_;
}
//==============================================================================
const GFA::Size & GFA::VectorArray::dim() const
{
    return dim_;
}
//==============================================================================
const GFA::Size & GFA::VectorArray::size() const
{
    return size_;
}
//==============================================================================
