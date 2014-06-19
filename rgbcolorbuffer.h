#ifndef GFA_RGBCOLORBUFFER_H
#define GFA_RGBCOLORBUFFER_H
//==============================================================================
#include "gfa_global.h"
#include "rgbcolor.h"
//==============================================================================
namespace GFA {

/*!
 * \brief The RGBColorBuffer class
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
