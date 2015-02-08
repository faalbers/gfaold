#ifndef _GFA_FRAME_H__
#define _GFA_FRAME_H__

#include "Space.h"
#include "Matrix.h"

class Point;
class Vector;

class Frame : public Matrix
{
public:
    Frame(void);
    Frame(const Frame &f);
    Frame(const Space &sp);
    Frame(const Point &p, const Vector &vx, const Vector &vy);

    Space   GetSpace(void) const;
    void    SetCoordinate(const Vector &v, const Index dim);

    void    SetPosition(const Point &p);    
    Matrix  GetMatrix(void) const;
    void    Print(void) const;
    
    //Frame & operator= (const Frame &rhs);
};

#endif

