#ifndef GFA_NORMAL_H
#define GFA_NORMAL_H
//==============================================================================
#include "gfa_global.h"
#include "vector3d.h"
//==============================================================================
namespace GFA {

class GFASHARED_EXPORT Normal
{
public:
    Normal();
    Normal(const Scalar &x_, const Scalar &y_, const Scalar &z_);

    Scalar x, y, z;

    Normal & operator= (const Vector3D &rhs);
};
}
#endif // GFA_NORMAL_H
