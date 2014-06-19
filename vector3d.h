#ifndef GFA_VECTOR3D_H
#define GFA_VECTOR3D_H
//==============================================================================
#include "gfa_global.h"
#include <iostream>
//==============================================================================
namespace GFA {

class Normal;

/*!
 * \brief The Vector3D class
 */
class GFASHARED_EXPORT Vector3D
{
public:
    Vector3D();
    Vector3D(const Scalar &x_, const Scalar &y_, const Scalar &z_);

    Scalar x, y, z;

    void normalize();

    // mathmatical operators
    Vector3D operator+ (const Vector3D &rhs) const;
    Vector3D operator- (const Vector3D &rhs) const;
    Vector3D operator* (const Scalar &rhs) const;
    Vector3D operator/ (const Scalar &rhs) const;
    Vector3D operator^ (const Vector3D &rhs) const;     // cross product
    GFA::Scalar operator* (const Vector3D &rhs) const;  // dot product
    GFA::Scalar operator* (const Normal &rhs) const;    // dot product
};
GFASHARED_EXPORT std::ostream & operator<< (std::ostream &os, const Vector3D &rhs);
}
#endif // GFA_VECTOR3D_H
