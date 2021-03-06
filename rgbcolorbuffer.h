#ifndef GFA_RGBCOLORBUFFER_H
#define GFA_RGBCOLORBUFFER_H
//==============================================================================
#include "gfa_global.h"
#include "rgbcolor.h"
//==============================================================================
namespace GFA {

/*!
 * \brief The RGBColorBuffer class
 *
 * A 2 dimensional pixel buffer. The buffer exists of an array of 4 consecutive
 * Scalar values. R(Red), G(Green),B(lue) and A(Alpha).
 */
class GFASHARED_EXPORT RGBColorBuffer
{
public:
    RGBColorBuffer();
    RGBColorBuffer(const Size &width, const Size &height);
    ~RGBColorBuffer();

    const Size & width() const;
    const Size & height() const;

    void setPixel(const Index &x, const Index &y, const RGBColor &col);

private:
    Size    width_;
    Size    height_;
    Size    size_;
    Scalar  *dataPtr_;
};
}
//==============================================================================
#endif // GFA_RGBCOLORBUFFER_H
