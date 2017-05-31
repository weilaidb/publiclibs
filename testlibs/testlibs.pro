TEMPLATE = app
CONFIG += console
CONFIG -= qt

INCLUDEPATH += include \
            unittest/include \
            utils/include

DEFINES += NN_HAVE_WINDOWS



SOURCES += main.cpp \
    unittest/ReadMe.cpp \
    utils/source/stringops.c \
    utils/source/slab.c \
    utils/source/log.c \
    utils/source/btree.c \
    utils/source/base64.c \
    utils/source/argv_split.c \
    utils/source/alloc.c \
    unittest/source/ut_string.cpp \
    unittest/source/ut_log.cpp \
    unittest/source/ut_list.cpp \
    unittest/source/ut_base64.cpp \
    unittest/source/ut_argv_split.cpp \
    unittest/source/ut_alloc.cpp \
    utils/source/mutex.c \
    utils/source/err.c \
    unittest/source/ut_mutex.cpp \
    utils/source/atomic.c \
    unittest/source/ut_atomic.cpp

HEADERS += \
    include/typedefs.h \
    include/defines.h \
    include/argv_split.h \
    include/commonheaders.h \
    include/stringops.h \
    include/list.h \
    include/wins.h\
    utils/include/slab.h \
    utils/include/log.h \
    utils/include/btree.h \
    utils/include/base64.h \
    utils/include/alloc.h \
    utils/include/err.h \
    unittest/include/ut_string.h \
    unittest/include/ut_log.h \
    unittest/include/ut_list.h \
    unittest/include/ut_base64.h \
    unittest/include/ut_argv_split.h \
    unittest/include/ut_alloc.h \
    unittest/include/ut_mutex.h \
    utils/include/atomic.h \
    unittest/source/ut_atomic.h
    utils/include/mutex.h \
    include/fast.h \
    include/nn.h \


