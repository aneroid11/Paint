#ifndef POLYGON_GLOBAL_H
#define POLYGON_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(POLYGON_LIBRARY)
#  define POLYGON_EXPORT Q_DECL_EXPORT
#else
#  define POLYGON_EXPORT Q_DECL_IMPORT
#endif

#endif // POLYGON_GLOBAL_H
