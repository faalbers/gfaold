//==============================================================================
#ifndef __GFA_NORMAL_H__
#define __GFA_NORMAL_H__
//==============================================================================
#include "GFA.h"
//==============================================================================
namespace GFA
{

class Vector3D;

class GFA_DLL_PUBLIC Normal
{
    public:
        Normal();
        Normal(const Scalar &x_, const Scalar &y_, const Scalar &z_);

        Scalar x, y, z;
        
        Normal & operator= (const Vector3D &rhs);

        // dot product
        GFA::Scalar operator* (const Normal &rhs) const;
        
};
}
//==============================================================================
#endif
//==============================================================================

