#include "Frame.h"
#include "Point.h"
#include "Vector.h"
#include "Utils.h"

Frame::Frame(void)
{
}

Frame::Frame(const Frame &f)
    : Matrix(f)
{
}

Frame::Frame(const Space &sp)
    : Matrix(sp.GetDimension()+1)
{
    MakeIdentity();
}

Frame::Frame(const Point &p, const Vector &vx, const Vector &vy)
{
    Space space = p.GetSpace();
    if ( space != Space(2) )
        throw Error("Frame::Frame", "Point space does not equal Frame Space");
    
    MakeIdentity(space);
    
    SetPosition(p);
    SetCoordinate(vx, 0);
    SetCoordinate(vy, 1);
}

Space Frame::GetSpace(void) const
{
    return Space(GetDimensionColumn()-1);
}

void Frame::SetCoordinate(const Vector &v, const Index dim)
{
    FillRow(v, dim);
}

Matrix  Frame::GetMatrix(void) const
{
    return Matrix(*this);
}

void Frame::SetPosition(const Point &p)
{
    if ( p.GetSpace() != GetSpace() )
        throw Error("Frame::SetPosition", "Point space does not equal Frame Space");

    Size dim = GetDimensionColumn();
    Index posIndex = dim * (dim + 1);
    for ( Index c = 0; c < dim; c++ )
        elements[posIndex + c] = p.GetIndex(c);
}


void Frame::Print(void) const
{
    std::cout << "Frame:" << std::endl;
    Matrix::Print();
}

/*
Space Frame::GetSpace(void) const
{
    return matrix.GetSpace();
}

*/
/*

Frame::~Frame(void)
{
    // Release vectors
    for ( int x = 0; x < coordinates.size(); x++ )
        if (coordinates[x] != 0)
            delete coordinates[x];
}

Frame::Frame(const Space &sp)
{
    coordinates.resize(sp.GetDimension());
    for ( int x = 0; x < coordinates.size(); x++ ) {
        coordinates[x] = new Vector(sp);
        coordinates[x]->SetIndexValue(x, 1.0);
    }
}

Frame & Frame::operator= (const Frame &rhs)
{
    int dim = rhs.GetSpace().GetDimension();
    coordinates.resize(dim);
    return *this;
}
*/
