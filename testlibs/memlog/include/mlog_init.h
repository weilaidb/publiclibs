#ifndef MLOG_INIT_H
#define MLOG_INIT_H
#include "memorylog.h"

//public
#define mlog_pushcommon(key, fmt,args...)\
do{\
    pushlogbyname(key,fmt,##args);\
}while(0)

//public package
#define mlog_pushcommonpackage(key, msg, msglen, fmt,args...)\
do{\
    pushmsgbyname(key,msg, msglen,fmt,##args);\
}while(0)




//��function��������
#define mlog_byfunc(fmt,args...)\
do{\
    char key[32];\
    snprintf(key, sizeof(key), "%s", __FUNCTION__);\
    pushlogbyname(key,fmt,##args);\
}while(0)


//��function��ʾ����
#define showmlog_byfunc \
do{\
    char key[32];\
    snprintf(key, sizeof(key), "%s", __FUNCTION__);\
    showmlogbyname(key);\
}while(0)

//��function��������package
#define mlogmsg_byfunc(msg, msglen, fmt,args...)\
do{\
    char key[32];\
    snprintf(key, sizeof(key), "%s", __FUNCTION__);\
    mlog_pushcommonpackage(key,msg, msglen, fmt,##args);\
}while(0)

#if 0
//��function��ʾ����package
#define showmlog_byfunc \
do{\
    char key[32];\
    snprintf(key, sizeof(key), "%s", __FUNCTION__);\
    showmlogbyname(key);\
}while(0)
#endif



#endif // MLOG_INIT_H
