#include "point3d.h"
#include "vector3d.h"
//==============================================================================
/*!
 * Constructor that sets the 3 axis scalars to zero.
 */
GFA::Point3D::Point3D() :
    x(0.0),
    y(0.0),
    z(0.0)
{
}
//==============================================================================
/*!
 * Constructor that sets the 3 axis scalars.
 *
 * \param x_ x-axis scalar
 * \param y_ y-axis scalar
 * \param z_ z-axis scalar
 */
GFA::Point3D::Point3D(const Scalar &x_, const Scalar &y_, const Scalar &z_) :
    x(x_),
    y(y_),
    z(z_)
{
}
//==============================================================================
/*!
 * Subtract with another Point3D that results into a Vector3D.
 *
 * \param rhs   Point3D to subtract with
 * \return      Vector3D
 */
GFA::Vector3D GFA::Point3D::operator-(const Point3D &rhs) const
{
    Vector3D temp;
    temp.x = x-rhs.x;
    temp.y = y-rhs.y;
    temp.z = z-rhs.z;
    return temp;
}
//==============================================================================
/*!
 * Add a Vector3D that results into a Point3D.
 *
 * \param rhs   Vector3D to add with
 * \return      Point3D
 */
GFA::Point3D GFA::Point3D::operator+(const Vector3D& rhs) const
{
    Point3D temp;
    temp.x = x+rhs.x;
    temp.y = y+rhs.y;
    temp.z = z+rhs.z;
    return temp;
}
//==============================================================================
std::ostream & GFA::operator<< (std::ostream &os, GFA::Point3D const &rhs)
{
    os << "Point3D(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    return os;
}
