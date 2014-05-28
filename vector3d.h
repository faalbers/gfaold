#ifndef GFA_VECTOR3D_H
#define GFA_VECTOR3D_H
//==============================================================================
#include "gfa_global.h"
//==============================================================================
namespace GFA {
class GFASHARED_EXPORT Vector3D
{
public:
    Vector3D();
    Vector3D(const Scalar &x_, const Scalar &y_, const Scalar &z_);

    Scalar x, y, z;
};
}
#endif // GFA_VECTOR3D_H
