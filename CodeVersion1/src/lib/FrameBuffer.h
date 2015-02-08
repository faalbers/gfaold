#ifndef _GFA_FRAMEBUFFER_H__
#define _GFA_FRAMEBUFFER_H__

#include "Types.h"

namespace GFA
{
class FrameBuffer
{
public:
    FrameBuffer(void);
    FrameBuffer(const Size width, const Size height);
    ~FrameBuffer(void);

    Size width() const;
    Size height() const;
    Size pixelCount() const;

    void setPixel(const Index &x, const Index &y,
        const Scalar &r, const Scalar &g, const Scalar &b, const Scalar &a = 1.0);

    void    Print(void) const;
    
private:
    Size    width_;
    Size    height_;
    Scalar  *data_;
                                  
};
}
#endif

