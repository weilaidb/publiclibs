#cmake最低版本需求，不加入此行会受到警告信息
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(PUBLICLIBS) #项目名称
#把当前目录(.)下所有源代码文件和头文件加入变量SRC_LIST
AUX_SOURCE_DIRECTORY(. SRC_LIST)
AUX_SOURCE_DIRECTORY(./utils/source SRC_LIST)
AUX_SOURCE_DIRECTORY(./unittest/source SRC_LIST)
include_directories(include)
include_directories(utils/include)
include_directories(unittest/include)
include_directories(unittest/source)
##target_link_libraries(pthread)
FIND_LIBRARY(RUNTIME_LIB rt /usr/lib  /usr/local/lib NO_DEFAULT_PATH)
link_libraries(${COMM_LIB} ${RUNTIME_LIB})


# ADD_DEFINITIONS(
# -O3 -g -W -Wall
 # -Wunused-variable -Wunused-parameter -Wunused-function -Wunused
 # -Wno-deprecated -Woverloaded-virtual -Wwrite-strings
 # -D__WUR= -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DTIXML_USE_STL
# )


##SET(SRC_LIST ${SRC_LIST} ${HEADERS})
#生成应用程序 publiclibs (在windows下会自动生成hello.exe)
ADD_EXECUTABLE(publiclibs ${SRC_LIST})
