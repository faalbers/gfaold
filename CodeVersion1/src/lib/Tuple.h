#ifndef _GFA_TUPLE_H__
#define _GFA_TUPLE_H__

#include "Types.h"
#include "Matrix.h"

namespace GFA
{
    class Tuple
    {
    public:    
        Tuple(void);
        Tuple(const Tuple &tupleRef);
        Tuple(const Size &cols);
        ~Tuple(void);

        void Resize(const Size &cols);
        const Size & GetSize(void) const;
        
        Tuple &         operator=(const Tuple &rhs);
        Tuple           operator*(const Matrix &rhs) const;
        Tuple           operator*(const Scalar &rhs) const;
        Scalar &        operator()(const Index &col);
        const Scalar &  operator()(const Index &col) const;
        
        void Print(void) const;
        
    protected:
        Size    cols_;
        Scalar  *dataPtr_;

        void CrossProd(Tuple &t, const Matrix &m) const;
        void Prod(Tuple &t, const Scalar &s) const;
    };
}

#endif

