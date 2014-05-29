#ifndef POINT2D_H
#define POINT2D_H
//==============================================================================
#include "gfa_global.h"
//==============================================================================
namespace GFA {
class GFASHARED_EXPORT Point2D
{
public:
    Point2D();
    Point2D(const Scalar &x_, const Scalar &y_);

    Scalar x, y;
};
}
#endif // POINT2D_H
