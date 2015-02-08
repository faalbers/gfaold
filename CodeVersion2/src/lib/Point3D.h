//==============================================================================
#ifndef __GFA_POINT3D_H__
#define __GFA_POINT3D_H__
//==============================================================================
#include "GFA.h"
#include <iostream>
//==============================================================================
namespace GFA
{

class Vector3D;

class GFA_DLL_PUBLIC Point3D
{
    public:
        Point3D();
        Point3D(const Scalar &x_, const Scalar &y_, const Scalar &z_);

        Scalar x, y, z;
        
        Vector3D    operator-(const Point3D &rhs) const;
        Point3D     operator+(const Vector3D& rhs) const;
};

GFA_DLL_PUBLIC std::ostream & operator<< (std::ostream &os, Point3D const &rhs);

}
//==============================================================================
#endif
//==============================================================================

