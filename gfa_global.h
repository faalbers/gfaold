#ifndef GFA_GLOBAL_H
#define GFA_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GFA_LIBRARY)
#  define GFASHARED_EXPORT Q_DECL_EXPORT
#else
#  define GFASHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GFA_GLOBAL_H
