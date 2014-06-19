#ifndef GFA_POINT3D_H
#define GFA_POINT3D_H
//==============================================================================
#include "gfa_global.h"
#include <iostream>
//==============================================================================
namespace GFA {

class Vector3D;

/*!
 * \brief The Point3D class
 */
class GFASHARED_EXPORT Point3D
{
public:
    Point3D();
    Point3D(const Scalar &x_, const Scalar &y_, const Scalar &z_);

    Scalar x, y, z;

    // mathmatical operators
    Vector3D    operator-(const Point3D &rhs) const;
    Point3D     operator+(const Vector3D& rhs) const;
};
GFASHARED_EXPORT std::ostream & operator<< (std::ostream &os, Point3D const &rhs);
}
#endif // GFA_POINT3D_H
//==============================================================================
