QT -= gui

TEMPLATE = lib
DEFINES += UTILS_LIBRARY

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    Acceleration.cpp \
    Displacement.cpp \
    Speed.cpp

HEADERS += \
    Acceleration.h \
    Displacement.h \
    Speed.h \
    utils_global.h

unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
