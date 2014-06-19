#ifndef GFA_RGBCOLOR_H
#define GFA_RGBCOLOR_H
//==============================================================================
#include "gfa_global.h"
#include <iostream>
//==============================================================================
namespace GFA {

/*!
 * \brief The RGBColor class
 */
class GFASHARED_EXPORT RGBColor
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
GFASHARED_EXPORT std::ostream & operator<< (std::ostream &os, RGBColor const &rhs);
}
//==============================================================================
#endif // GFA_RGBCOLOR_H
