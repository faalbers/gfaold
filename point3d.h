#ifndef GFA_POINT3D_H
#define GFA_POINT3D_H
//==============================================================================
#include "gfa_global.h"
//==============================================================================
namespace GFA {
class GFASHARED_EXPORT Point3D
{
public:
    Point3D();
    Point3D(const Scalar &x_, const Scalar &y_, const Scalar &z_);

    Scalar x, y, z;
};
}
#endif // GFA_POINT3D_H
//==============================================================================
