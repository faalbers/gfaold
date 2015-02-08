#include "Matrix.h"
#include "Utils.h"
#include <iostream>

GFA::Matrix::Matrix(void)
    :   rows_(0),
        cols_(0),
        data_(0)
{
    if (LOG_DEBUG) std::cout << "Create Matrix at " << this << " with no data." << std::endl;
}

GFA::Matrix::Matrix(const Matrix &m)
    :   rows_(m.rows_),
        cols_(m.cols_),
        data_(0)
{
    if (LOG_DEBUG) std::cout << "Matrix copy constructor creating " << this;
    if (rows_ == 0 || cols_ == 0) {
        if (LOG_DEBUG) std::cout << " with no data" << std::endl;
        rows_ = cols_ = 0;
        return;
    }

    Size dataSize = rows_ * cols_;
    if (LOG_DEBUG) std::cout << " and Create array of " << dataSize << " Scalars";
    data_ = new Scalar[dataSize];
    if (LOG_DEBUG) std::cout << " starting at " << data_ << std::endl;
    for (Index i = 0; i < dataSize; i++) {
        if (LOG_DEBUG) std::cout << "Copy content from " << &m.data_[i] << " to " << &data_[i] << std::endl;
        data_[i] = m.data_[i];
    }
}

GFA::Matrix::Matrix(const Size rows, const Size cols)
    :   rows_(rows),
        cols_(cols),
        data_(0)
{
    if (LOG_DEBUG) std::cout << "Create Matrix at " << this;
    if (rows_ == 0 || cols_ == 0) {
        std::cout << " with no data" << std::endl;
        return;
    }
    
    Size dataSize = rows_ * cols_;
    if (LOG_DEBUG) std::cout << " and Create array of " << dataSize << " Scalars";
    data_ = new Scalar[dataSize];
    if (LOG_DEBUG) std::cout << " starting at " << data_ << std::endl;
    for (Index i = 0; i < dataSize; i++)
        data_[i] = 0;
}

GFA::Matrix::~Matrix(void)
{
    if ( data_ != 0 ) {
        if (LOG_DEBUG) std::cout << "Delete array of " << cols_ << " Scalars starting at " << data_ << " and ";
        delete[] data_;
    }
    if (LOG_DEBUG) std::cout << "Delete Matrix at " << this << std::endl;
}

void GFA::Matrix::Resize(const Size rows, const Size cols)
{
    Size fullSize = rows_ * cols_;
    Size fullSizeResize = rows * cols;
    if (fullSize != fullSizeResize) {
        if (data_ != 0) {
            delete[] data_;
            data_ = 0;
            rows_ = 0;
            cols_ = 0;
        }
        if (fullSizeResize != 0) {
            data_ = new Scalar[fullSizeResize];
            rows_ = rows;
            cols_ = cols;
        }
    }
    for (Index i = 0; i < fullSizeResize; i++)
        data_[i] = 0;
}

const GFA::Size & GFA::Matrix::GetRowSize(void) const
{
    return rows_;
}

const GFA::Size & GFA::Matrix::GetColumnSize(void) const
{
    return cols_;
}

GFA::Matrix & GFA::Matrix::operator=(const Matrix& rhs)
{
    Size thisSize = rows_ * cols_;
    Size rhsSize  = rhs.rows_ * rhs.cols_;

    if (thisSize != rhsSize) {
        if (data_ != 0)
            delete[] data_;
        data_ = new Scalar[rhsSize];
        rows_ = rhs.rows_;
        cols_ = rhs.cols_;
    }

    for (Index i = 0; i < rhsSize; i++)
        data_[i] = rhs.data_[i];
    
    return *this;
}

GFA::Matrix GFA::Matrix::operator*(const Matrix &rhs) const
{
    Matrix temp;
    CrossProd(temp, rhs);
    return temp;
}

GFA::Scalar & GFA::Matrix::operator() (const Index row, const Index col)
{
    if (row >= rows_ || col >= cols_)
        throw Error("GFA::Matrix::operator()", "Matrix subscript out of bound");
    return data_[row * cols_ + col];
}

const GFA::Scalar & GFA::Matrix::operator() (const Index row, const Index col) const
{
    if (row >= rows_ || col >= cols_)
        throw Error("const GFA::Matrix::operator()", "Matrix subscript out of bound");
    return data_[row * cols_ + col];
}

void GFA::Matrix::Print(void) const
{
    Index startIndex;
    for ( Index r = 0; r < rows_; r++ ) {
        startIndex = cols_ * r;
        std::cout << "|";
        for ( Index c = 0; c < cols_ ; c++ ) {
            if (c == 0)
                std::cout << data_[startIndex + c];
            else
                std::cout << ", " << data_[startIndex + c];
        }
        std::cout << "|" << std::endl;
    }
    std::cout << std::endl;
}

void GFA::Matrix::MakeIdentity(void)
{
    if (rows_ != cols_)
        throw Error("GFA::Matrix::MakeIdentity", "Matrix has different rows and columns count");
    for ( Index r = 0; r < rows_; r++ ) {
        for ( Index c = 0; c < cols_ ; c++ ) {
            if ( r == c )
                data_[r*cols_ + c] = 1.0;
            else
                data_[r*cols_ + c] = 0.0;
        }
    }
}

void GFA::Matrix::MakeTranslate(const Scalar x, const Scalar y, const Scalar z)
{
    if (rows_ == 0)
        throw Error("GFA::Matrix::MakeTranslate", "Matrix has no rows");
    Index translateRow = rows_ - 1;
    MakeIdentity();
    if (translateRow >= 3)
        data_[translateRow*cols_ + 2] = z;
    if (translateRow >= 2)
        data_[translateRow*cols_ + 1] = y;
    if (translateRow >= 1)
        data_[translateRow*cols_ + 0] = x;
}

void GFA::Matrix::CrossProd(Matrix &m1, const Matrix &m2) const
{
    if ( cols_ != m2.rows_ )
        throw Error("GFA::Matrix::CrossProd",
            "Matrix column size not equal to Matrix row size");

    m1.Resize(rows_, m2.cols_);
    Scalar value;
    Index rm, cm, cm2;
    for ( rm = 0; rm < rows_; rm++ ) {
        for ( cm2 = 0; cm2 < m2.cols_; cm2++ ) {
            value = 0.0;
            for ( cm = 0; cm < cols_; cm++ )
                value += data_[rm * cols_ + cm] * m2.data_[cm * m2.cols_ + cm2];
            m1(rm,cm2) = value;
        }
    }
}
