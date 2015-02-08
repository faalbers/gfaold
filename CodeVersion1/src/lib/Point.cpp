#include "Point.h"
//#include "Frame.h"
//#include "Space.h"
//#include "Utils.h"
//#include "Vector.h"
//#include "Math.h"
#include "Utils.h"

GFA::Point::Point()
    : Tuple(1)
{
    if (LOG_DEBUG) std::cout << "Create Point at " << this << std::endl;
    // Last scalar for point is 1.0
    dataPtr_[0] = 1.0;
}

GFA::Point::Point(const Size &cols)
    : Tuple(cols+1)
{
    if (LOG_DEBUG) std::cout << "Create Point at " << this << " with " << cols << " dimensions" << std::endl;
    dataPtr_[cols] = 1.0;
}

GFA::Point GFA::Point::operator*(const Matrix &rhs) const
{
    Point temp;
    CrossProd(temp, rhs);
    return temp;
}

/*
Point::Point(const Space &sp)
    : Tuple(sp.GetDimension()+1)
{
    // Last scalar for point is 1.0
    elements[sp.GetDimension()] = 1.0;
}

Point::Point(const Frame &f, const Scalar x, const Scalar y)
{
    if ( f.GetSpace() != Space(2) )
        throw Error("Point::Point", "Frame space does not equal Point Space");
    
    elements.reserve(3);
    elements.push_back(x);
    elements.push_back(y);
    elements.push_back(1.0);
    
    Tuple temp = CrossMult(*this, f.GetMatrix());

    elements = temp.GetVec();
}

Space Point::GetSpace(void) const
{
    return Space(GetDimension() - 1);
}


Point Point::operator*(const Matrix &rhs) const
{
    return Point(Tuple::operator*(rhs));
}

Point Point::operator*(const Scalar &rhs) const
{
    Point temp(*this);
    temp.Mult(rhs);
    
    return temp;
}

Vector Point::operator-(const Point &rhs) const
{
    Point temp(*this);
    temp.Sub(rhs);
    
    return Vector(temp);
}

Point Point::operator+(const Vector &rhs) const
{
    Point temp(*this);
    temp.Add(rhs);
    
    return temp;
}
*/

void GFA::Point::Print(void) const
{
    std::cout << "Point(";
    for ( Index c = 0; c < (cols_-1); c++ )
        if ( c == 0 )
            std::cout << dataPtr_[c];
        else
            std::cout << ", " << dataPtr_[c];
    std::cout << ")" << std::endl;
    std::cout << std::endl;
}


