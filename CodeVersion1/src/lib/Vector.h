#ifndef _GFA_VECTOR_H__
#define _GFA_VECTOR_H__

#include "Tuple.h"
#include "Types.h"
//#include <vector>
//#include "Space.h"

//class Frame;
//class Point;
namespace GFA
{
    class Vector : public Tuple
    {
    public:
        Vector(void);
        Vector(const Size &cols);
        //Vector(const Space &sp);
        //Vector(const Frame &f,  const Scalar x, const Scalar y);

        Vector operator*(const Matrix &rhs) const;    

        //Space   GetSpace(void) const;
        void Print(void) const;
        //Scalar Length();
        
        //Vector + Vector = Vector
        //Vector . Vector = Scalar
        //Vector operator*(const Matrix &rhs) const;
        //Vector operator*(const Scalar &rhs) const;
    };
}

#endif


