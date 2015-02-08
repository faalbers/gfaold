//==============================================================================
#ifndef __GFA_RGBCOLORBUFFER_H__
#define __GFA_RGBCOLORBUFFER_H__
//==============================================================================
#include "GFA.h"
//==============================================================================
namespace GFA
{

class RGBColor;

class GFA_DLL_PUBLIC RGBColorBuffer
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
#endif
//==============================================================================

