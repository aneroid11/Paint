#ifndef LINES_GLOBAL_H
#define LINES_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LINES_LIBRARY)
#  define LINES_EXPORT Q_DECL_EXPORT
#else
#  define LINES_EXPORT Q_DECL_IMPORT
#endif

#endif // LINES_GLOBAL_H
