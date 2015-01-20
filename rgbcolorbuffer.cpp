#include "rgbcolorbuffer.h"
//==============================================================================
GFA::RGBColorBuffer::RGBColorBuffer() :
    width_(0),
    height_(0),
    size_(0),
    dataPtr_(0)
{
}
//==============================================================================
/*!
 * Constructor that creates a 2 dimensional pixel buffer based on given x and y
 * size. The buffer exists of 4 consecutive Scalar values. R(Red), G(Green),
 * B(lue) and A(Alpha).
 */
GFA::RGBColorBuffer::RGBColorBuffer(const Size &width, const Size &height)
    :   width_(width),
        height_(height),
        size_((width_*4)*height_),
        dataPtr_(new Scalar[size_])
{
}
//==============================================================================
GFA::RGBColorBuffer::~RGBColorBuffer()
{
   if (dataPtr_ != 0) delete[] dataPtr_;
}
//==============================================================================
const GFA::Size & GFA::RGBColorBuffer::width() const
{
    return width_;
}
//==============================================================================
const GFA::Size & GFA::RGBColorBuffer::height() const
{
    return height_;
}
//==============================================================================
void GFA::RGBColorBuffer::setPixel(
    const Index &, const Index &, const RGBColor &)
{
    //NOTE: Dees to be set up
}
