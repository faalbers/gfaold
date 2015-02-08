#include "Tuple.h"
#include "Utils.h"
#include <iostream>

GFA::Tuple::Tuple(void)
    :   cols_(0),
        dataPtr_(0)
{
    if (LOG_DEBUG) std::cout << "Create Tuple at " << this << " with no data." << std::endl;
}

GFA::Tuple::Tuple(const Tuple &tupleRef)
    :   cols_(tupleRef.cols_),
        dataPtr_(0)
{
    if (LOG_DEBUG) std::cout << "Copy from tupleRef at " << &tupleRef << " into Tuple at " << this;
    if (cols_ == 0) {
        if (LOG_DEBUG) std::cout << " with no data" << std::endl;
        return;
    }
    if (LOG_DEBUG) std::cout << " and Create array of " << cols_ << " Scalars";
    dataPtr_ = new Scalar[cols_];
    if (LOG_DEBUG) std::cout << " starting at " << dataPtr_ << std::endl;
    for (Index i = 0; i < cols_; i++) {
        if (LOG_DEBUG) std::cout << "Copy content from " << &tupleRef.dataPtr_[i] << " to " << &dataPtr_[i] << std::endl;
        dataPtr_[i] = tupleRef.dataPtr_[i];
    }
}

GFA::Tuple::Tuple(const Size &cols)
    :   cols_(cols),
        dataPtr_(0)
{
    
    if (LOG_DEBUG) std::cout << "Create Tuple at " << this;
    if (cols_ == 0) {
        if (LOG_DEBUG) std::cout << " with no data" << std::endl;
        return;
    }
    if (LOG_DEBUG) std::cout << " and Create array of " << cols_ << " Scalars";
    dataPtr_ = new Scalar[cols_];
    if (LOG_DEBUG) std::cout << " starting at " << dataPtr_ << std::endl;
    for (Index i = 0; i < cols_; i++) dataPtr_[i] = 0;
}

GFA::Tuple::~Tuple(void)
{
    if ( dataPtr_ != 0 ) {
        if (LOG_DEBUG) std::cout << "Delete array of " << cols_ << " Scalars starting at " << dataPtr_ << " and ";
        delete[] dataPtr_;
    }
    if (LOG_DEBUG) std::cout << "Destruct Tuple at " << this << std::endl;
}

void GFA::Tuple::Resize(const Size &cols)
{   
    if (cols != cols_) {
        if (LOG_DEBUG) std::cout << "Resize Tuple at " << this << " from " << cols_ << " to " << cols << std::endl;
        if (dataPtr_ != 0) {
            if (LOG_DEBUG) std::cout << "Delete arrays of " << cols_ << " Scalars starting at " << dataPtr_ << std::endl;
            delete[] dataPtr_;
            dataPtr_ = 0;
            cols_ = 0;
        }
        if (cols != 0) {
            dataPtr_ = new Scalar[cols];
            if (LOG_DEBUG) std::cout << "Created arrays of " << cols_ << " Scalars starting at " << dataPtr_ << std::endl;
            cols_ = cols;
        }
    }
    for (Index i = 0; i < cols_; i++)
        dataPtr_[i] = 0;
}

const GFA::Size & GFA::Tuple::GetSize(void) const
{
    return cols_;
}

GFA::Tuple & GFA::Tuple::operator=(const Tuple& rhs)
{
    if (LOG_DEBUG) std::cout << "Tuple " << this << " operator= with rhd " << &rhs << std::endl;
    if (cols_ != rhs.cols_) {
        if (dataPtr_ != 0) {
            if (LOG_DEBUG) std::cout << "Delete array of " << cols_ << " Scalars starting at " << dataPtr_ << std::endl;
            delete[] dataPtr_;
            dataPtr_ = 0;
        }
        cols_ = rhs.cols_;
        if (LOG_DEBUG) std::cout << "Create array of " << cols_ << " Scalars";
        dataPtr_ = new Scalar[cols_];
        if (LOG_DEBUG) std::cout << " starting at " << dataPtr_ << std::endl;
    }

    for (Index i = 0; i < cols_; i++) {
        if (LOG_DEBUG) std::cout << "Copy content from " << &rhs.dataPtr_[i] << " to " << &dataPtr_[i] << std::endl;
        dataPtr_[i] = rhs.dataPtr_[i];
    }

    
    return *this;
}

GFA::Tuple GFA::Tuple::operator*(const Matrix &rhs) const
{
    Tuple temp;
    CrossProd(temp, rhs);
    return temp;
}

GFA::Tuple GFA::Tuple::operator*(const Scalar &rhs) const
{
    Tuple temp;
    Prod(temp, rhs);
    return temp;
}

GFA::Scalar & GFA::Tuple::operator() (const Index &col)
{
    if (col >= cols_)
        throw Error("GFA::Tuple::operator()", "Tuple subscript out of bound");
    return dataPtr_[col];
}

const GFA::Scalar & GFA::Tuple::operator() (const Index &col) const
{
    if (col >= cols_)
        throw Error("const GFA::Tuple::operator()", "Tuple subscript out of bound");
    return dataPtr_[col];
}

void GFA::Tuple::Print(void) const
{
    std::cout << "(";
    for ( Index c = 0; c < cols_; c++ )
        if ( c == 0 )
            std::cout << dataPtr_[c];
        else
            std::cout << ", " << dataPtr_[c];
    std::cout << ")" << std::endl;
    std::cout << std::endl;
}

void GFA::Tuple::CrossProd(Tuple &t, const Matrix &m) const
{
    if ( cols_ != m.GetRowSize() )
    throw Error("GFA::Tuple::CrossProd",
            "Tuple size not equal to Matrix column size");

    t.Resize(m.GetColumnSize());
    Scalar value;
    for ( Index cm = 0; cm < m.GetColumnSize(); cm++ ) {
        value = 0.0;
        for ( Index r = 0; r < cols_; r++ )
            value += dataPtr_[r] * m(r, cm);
        t(cm) = value;
    }
}

void GFA::Tuple::Prod(Tuple &t, const Scalar &s) const
{
    t = *this;
    for ( Index cs = 0; cs < t.cols_; cs++ ) t.dataPtr_[cs] *= s;
}

