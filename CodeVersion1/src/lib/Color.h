#ifndef _GFA_COLOR_H__
#define _GFA_COLOR_H__

#include "Tuple.h"
#include "Types.h"

namespace GFA
{
class Color : public Tuple
{
public:
    Color(void);
    Color(const Scalar r, const Scalar g, const Scalar b, const Scalar a = 1.0);

    void        Print(void) const;
                                  
};
}
#endif

