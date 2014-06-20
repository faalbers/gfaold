#ifndef GFA_GFA_GLOBAL_H
#define GFA_GFA_GLOBAL_H

/*! \mainpage GFA Graphic Library
 *
 * \section intro_sec Introduction
 *
 * This Library contains all the basic elements needed for Computer Graphics
 * programming.
 * Still in progress.
 */

#include <QtCore/qglobal.h>

#if defined(GFA_LIBRARY)
#  define GFASHARED_EXPORT Q_DECL_EXPORT
#else
#  define GFASHARED_EXPORT Q_DECL_IMPORT
#endif

namespace GFA {
typedef double          Scalar;
typedef unsigned int    Index;
typedef unsigned int    Size;

const Scalar EPSILON        = 0.0001; // very small
const Scalar HUGE_SCALAR    = 1.0E10; // very large
const Scalar PI             = 3.14159265359;
const Scalar invPI          = 1.0 / PI;
}

#endif // GFA_GFA_GLOBAL_H
