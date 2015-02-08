#ifndef _GFA_SPACE_H__
#define _GFA_SPACE_H__

#include "Types.h"

namespace GFA
{
    class Space
    {
    public:
        Space();
        Space(const Size dim);
    
        Size GetDimension(void) const;
    
        //bool operator!=(const Space &other) const;
        void Print(void) const;
        
    private:
        Size dim_;
    };
}
#endif


