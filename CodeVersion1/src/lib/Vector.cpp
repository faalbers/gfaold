#include "Vector.h"
//#include "Frame.h"
//#include "Math.h"
//#include "Utils.h"
//#include "Point.h"
#include <iostream>

GFA::Vector::Vector()
    : Tuple(1)
{
    // Last scalar for vector is 0.0
    dataPtr_[0] = 0.0;
}

GFA::Vector::Vector(const Size &cols)
    : Tuple(cols+1)
{
    dataPtr_[cols] = 0.0;
}

GFA::Vector GFA::Vector::operator*(const Matrix &rhs) const
{
    Vector temp;
    CrossProd(temp, rhs);
    return temp;
}
/*
Vector::Vector(const Space &sp)
    : Tuple(sp.GetDimension()+1)
{
    // Last scalar for vector is 0.0
    elements[sp.GetDimension()] = 0.0;
}

Vector::Vector(const Frame &f,  const Scalar x, const Scalar y)
{
    if ( f.GetSpace() != Space(2) )
        throw Error("Vector::Vector", "Frame space does not equal Vector Space");
    
    elements.reserve(3);
    elements.push_back(x);
    elements.push_back(y);
    elements.push_back(0.0);
    
    Tuple temp = CrossMult(*this, f.GetMatrix());

    elements = temp.GetVec();
}

Vector Vector::operator*(const Matrix &rhs) const
{
    return Vector(Tuple::operator*(rhs));
}

Vector Vector::operator*(const Scalar &rhs) const
{
    Vector temp(*this);
    temp.Mult(rhs);
    
    return temp;
}

Scalar Vector::Length()
{
   //sqrt(Vector . Vector)
   return 0.0;
}
*/

void GFA::Vector::Print(void) const
{
    std::cout << "Vector(";
    for ( Index c = 0; c < (cols_-1); c++ )
        if ( c == 0 )
            std::cout << dataPtr_[c];
        else
            std::cout << ", " << dataPtr_[c];
    std::cout << ")" << std::endl;
    std::cout << std::endl;
}

