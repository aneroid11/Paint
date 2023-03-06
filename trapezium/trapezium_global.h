#ifndef TRAPEZIUM_GLOBAL_H
#define TRAPEZIUM_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TRAPEZIUM_LIBRARY)
#  define TRAPEZIUM_EXPORT Q_DECL_EXPORT
#else
#  define TRAPEZIUM_EXPORT Q_DECL_IMPORT
#endif

#endif // TRAPEZIUM_GLOBAL_H
