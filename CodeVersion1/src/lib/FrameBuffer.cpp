#include "FrameBuffer.h"
#include "Utils.h"
#include <iostream>

GFA::FrameBuffer::FrameBuffer(void)
    :   width_(0),
        height_(0),
        data_(0)
{
    if (LOG_DEBUG) std::cout << "Create FrameBuffer at " << this << " with no data " << std::endl;
}

GFA::FrameBuffer::FrameBuffer(const Size width, const Size height)
    :   width_(width),
        height_(height),
        data_(0)
{
    if (LOG_DEBUG) std::cout << "Create FrameBuffer at " << this;
    if (width_ == 0 || height_ == 0) {
        std::cout << " with no data" << std::endl;
        width_ = height_ = 0;
        return;
    }
    Size pixCount = pixelCount();
    Size dataSize = pixCount * 4;
    if (LOG_DEBUG) std::cout << " and Create array of " << pixCount << " Pixels (" << dataSize << " Scalars)";
    data_ = new Scalar[dataSize];
    if (LOG_DEBUG) std::cout << " starting at " << data_ << std::endl;
    for (Index i = 0; i < pixCount; i++) {
        data_[i*4] = 0.0;
        data_[i*4+1] = 0.0;
        data_[i*4+2] = 0.0;
        data_[i*4+3] = 1.0;
    }
}

GFA::FrameBuffer::~FrameBuffer(void)
{
    if ( data_ != 0 ) {
        if (LOG_DEBUG) std::cout << "Delete array of " << width_ * height_ << " Pixels (" << width_ * height_ * 4 << " Scalars) starting at " << data_ << " and ";
        delete[] data_;
    }
    if (LOG_DEBUG) std::cout << "Delete FrameBuffer at " << this << std::endl;
}

GFA::Size GFA::FrameBuffer::width() const
{
    return width_;
}

GFA::Size GFA::FrameBuffer::height() const
{
    return height_;
}

GFA::Size GFA::FrameBuffer::pixelCount() const
{
    return width_ * height_;
}

void GFA::FrameBuffer::setPixel(const Index &x, const Index &y,
        const Scalar &r, const Scalar &g, const Scalar &b, const Scalar &a)
{
    if ( x >= width_ || y >= height_ )
        throw Error("GFA::FrameBuffer::setPixel()", "Pixel index out of bound");
        
    data_[x*4 + y*width_*4]     = r;
    data_[x*4 + y*width_*4 + 1] = g;
    data_[x*4 + y*width_*4 + 2] = b;
    data_[x*4 + y*width_*4 + 3] = a;
}

void    GFA::FrameBuffer::Print(void) const
{
}


