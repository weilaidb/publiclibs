TEMPLATE = app
CONFIG += console
CONFIG -= qt

INCLUDEPATH += include \
            unittest/libs

SOURCES += main.cpp \
    lib/argv_split.c \
    unittest/libs/ut_argv_split.cpp \
    unittest/libs/ut_string.cpp \
    lib/stringops.c \
    unittest/ReadMe.cpp \
    lib/ReadMe.c \
    lib/btree.c \
    lib/slab.c

HEADERS += \
    include/typedefs.h \
    include/defines.h \
    include/argv_split.h \
    unittest/libs/ut_argv_split.h \
    unittest/libs/ut_string.h \
    include/commonheaders.h \
    include/stringops.h \
    lib/btree.h \
    lib/slab.h


