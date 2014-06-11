#ifndef GFA_NORMAL_H
#define GFA_NORMAL_H
//==============================================================================
#include "gfa_global.h"
#include <iostream>
//==============================================================================
namespace GFA {

class Vector3D;

class GFASHARED_EXPORT Normal
{
public:
    Normal();
    Normal(const Scalar &x_, const Scalar &y_, const Scalar &z_);

    Scalar x, y, z;

    Normal & operator= (const Vector3D &rhs);
};
GFASHARED_EXPORT std::ostream & operator<< (std::ostream &os, const Normal &rhs);
}
#endif // GFA_NORMAL_H
