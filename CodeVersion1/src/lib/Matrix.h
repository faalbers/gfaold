#ifndef _GFA_MATRIX_H__
#define _GFA_MATRIX_H__

#include "Types.h"

namespace GFA
{
class Matrix
{
public:    
    Matrix(void);
    Matrix(const Matrix &m);
    Matrix(const Size rows, const Size cols);
    ~Matrix(void);

    void Resize(const Size rows, const Size cols);
    const Size & GetRowSize(void) const;
    const Size & GetColumnSize(void) const;
    
    Matrix &        operator=(const Matrix& rhs);
    Matrix          operator*(const Matrix &rhs) const;
    Scalar &        operator()(const Index row, const Index col);
    const Scalar &  operator()(const Index row, const Index col) const;
    
    void Print(void) const;
    void MakeIdentity(void);
    void MakeTranslate(const Scalar x = 0.0, const Scalar y = 0.0, const Scalar z = 0.0);
    //void MakeScale(void);
    
protected:
    Size    rows_;
    Size    cols_;
    Scalar  *data_;

    void CrossProd(Matrix &m1, const Matrix &m2) const;
};
}

#endif

