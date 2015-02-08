#ifndef _GFA_POINT_H__
#define _GFA_POINT_H__

#include "Tuple.h"
#include "Types.h"
//#include "Matrix.h"

//class Frame;
//class Vector;
namespace GFA
{
    class Point : public Tuple
    {
    public:
        Point(void);
        Point(const Size &cols);
        //Point(const Space &sp);
        //Point(const Frame &f, const Scalar x, const Scalar y);
       
        //Space   GetSpace(void) const;
        Point   operator*(const Matrix &rhs) const;

        void    Print(void) const;
                                      
        //Point + Vector = Point
        //Point - Point = Vector
        //Point   operator*(const Matrix &rhs) const;
        //Point   operator*(const Scalar &rhs) const;
        //Vector  operator-(const Point &rhs) const;
        //Point   operator+(const Vector &rhs) const;
    };
}
#endif


