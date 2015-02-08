#ifndef __GFA_RGBCOLOR_H__
#define __GFA_RGBCOLOR_H__
//==============================================================================
#include "GFA.h"
#include <iostream>
//==============================================================================
namespace GFA
{
class GFA_DLL_PUBLIC RGBColor
{
    public:
        RGBColor();
        RGBColor(
            const Scalar &r_, 
            const Scalar &g_,
            const Scalar &b_,
            const Scalar &a = 1.0);

        Scalar r, g, b, a;

        RGBColor   operator* (const Scalar &rhs) const;
        RGBColor   operator* (const RGBColor &rhs) const;
        RGBColor & operator= (const RGBColor &rhs);
        RGBColor & operator+= (const RGBColor &rhs);
        RGBColor & operator/= (const Scalar &rhs);
        RGBColor & operator*= (const RGBColor &rhs);
        RGBColor & operator*= (const Scalar &rhs);
};

GFA_DLL_PUBLIC std::ostream & operator<< (std::ostream &os, RGBColor const &rhs);

}
//==============================================================================
#endif

