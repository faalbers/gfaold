#include "vector3d.h"
//==============================================================================
GFA::Vector3D::Vector3D() :
    x(0.0),
    y(0.0),
    z(0.0)
{
}
//==============================================================================
GFA::Vector3D::Vector3D(const Scalar &x_, const Scalar &y_, const Scalar &z_) :
    x(x_),
    y(y_),
    z(z_)
{
}
//==============================================================================
void GFA::Vector3D::normalize()
{
    GFA::Scalar dom = 1.0 / sqrt(x*x + y*y + z*z);
    x *= dom;
    y *= dom;
    z *= dom;
}
