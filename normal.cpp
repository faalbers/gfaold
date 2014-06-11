#include "normal.h"
#include "vector3d.h"
//==============================================================================
GFA::Normal::Normal() :
    x(0.0),
    y(0.0),
    z(0.0)
{
}
//==============================================================================
GFA::Normal::Normal(const Scalar &x_, const Scalar &y_, const Scalar &z_) :
    x(x_),
    y(y_),
    z(z_)
{
}
//==============================================================================
GFA::Normal & GFA::Normal::operator= (const Vector3D &rhs)
{
    x = rhs.x; y = rhs.y; z = rhs.z;
    return (*this);
}
//==============================================================================
std::ostream & GFA::operator<< (std::ostream &os, const GFA::Normal &rhs)
{
    os << "Normal(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    return os;
}
