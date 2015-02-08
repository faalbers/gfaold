#ifndef __GFA_POINT2D_H__
#define __GFA_POINT2D_H__
//==============================================================================
#include "GFA.h"
#include <iostream>
//==============================================================================
namespace GFA
{
class GFA_DLL_PUBLIC Point2D
{
    public:
        Point2D();
        Point2D(const Scalar &x_, const Scalar &y_);
        
        Scalar x, y;
};

GFA_DLL_PUBLIC std::ostream & operator<< (std::ostream &os, Point2D const &rhs);

}
//==============================================================================
#endif

