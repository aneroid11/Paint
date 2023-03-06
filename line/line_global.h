#ifndef LINE_GLOBAL_H
#define LINE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LINE_LIBRARY)
#  define LINE_EXPORT Q_DECL_EXPORT
#else
#  define LINE_EXPORT Q_DECL_IMPORT
#endif

#endif // LINE_GLOBAL_H
