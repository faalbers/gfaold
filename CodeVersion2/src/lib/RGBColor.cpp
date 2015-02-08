#include "RGBColor.h"
//==============================================================================
GFA::RGBColor::RGBColor()
    :   r(0.0),
        g(0.0),
        b(0.0),
        a(1.0)
{
}
//==============================================================================
GFA::RGBColor::RGBColor(
    const Scalar &r_,
    const Scalar &g_,
    const Scalar &b_,
    const Scalar &a_)
    :   r(r_),
        g(g_),
        b(b_),
        a(a_)
{
}
//==============================================================================
GFA::RGBColor GFA::RGBColor::operator* (const Scalar &rhs) const
{
    return RGBColor(r * rhs, g * rhs, b * rhs, a * rhs);
}
//==============================================================================
GFA::RGBColor GFA::RGBColor::operator* (const RGBColor& rhs) const
{
    return RGBColor(r * rhs.r, g * rhs.g, b * rhs.b, a * rhs.a);
}
//==============================================================================
GFA::RGBColor & GFA::RGBColor::operator= (const RGBColor &rhs)
{
	r = rhs.r; g = rhs.g; b = rhs.b; a = rhs.a;

	return (*this);
}
//==============================================================================
GFA::RGBColor & GFA::RGBColor::operator+= (const RGBColor &rhs)
{
	r += rhs.r; g += rhs.g; b += rhs.b; a += rhs.a;

	return (*this);
}
//==============================================================================
GFA::RGBColor & GFA::RGBColor::operator/= (const Scalar &rhs)
{
	r /= rhs; g /= rhs; b /= rhs; a /= rhs;

	return (*this);
}
//==============================================================================
GFA::RGBColor & GFA::RGBColor::operator*= (const RGBColor &rhs)
{
	r *= rhs.r; g *= rhs.g; b *= rhs.b; a *= rhs.a;

	return (*this);
}
//==============================================================================
GFA::RGBColor & GFA::RGBColor::operator*= (const Scalar &rhs)
{
	r *= rhs; g *= rhs; b *= rhs; a *= rhs;

	return (*this);
}
//==============================================================================
std::ostream & GFA::operator<< (std::ostream &os, const GFA::RGBColor &rhs)
{
    os << "RGBColor(" << rhs.r << ", " << rhs.g << ", " << rhs.b << ", " << rhs.a << ")";
    return os;
}
//==============================================================================

