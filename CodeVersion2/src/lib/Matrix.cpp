#include "Matrix.h"
//==============================================================================
GFA::Matrix::Matrix(const Size &cols, const Size &rows)
    :   dataPtr_(new Scalar[cols*rows]),
        cols_(cols),
        rows_(rows)
{
}
//==============================================================================
GFA::Matrix::~Matrix()
{
   delete[] dataPtr_;
}
//==============================================================================
const GFA::Size & GFA::Matrix::columns() const
{
    return cols_;
}
//==============================================================================
const GFA::Size & GFA::Matrix::rows() const
{
    return rows_;
}
//==============================================================================
