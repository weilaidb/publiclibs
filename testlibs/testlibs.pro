TEMPLATE = app
CONFIG += console
CONFIG -= qt

INCLUDEPATH += include \
            unittest/libs

SOURCES += main.cpp \
    lib/argv_split.c \
    unittest/libs/ut_argv_split.cpp

HEADERS += \
    include/typedefs.h \
    include/defines.h \
    include/argv_split.h \
    unittest/libs/ut_argv_split.h


