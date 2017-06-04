#include "commonheaders.h"
#include "ut_literal.h"
#include "defines.h"

#ifdef __cplusplus 
extern "C" {
#endif
#include "literal.h"
#ifdef __cplusplus 
}
#endif

#ifndef NN_HAVE_WINDOWS
#include <arpa/inet.h>
#include <netinet/in.h>
#endif



/*============================================
* FuncName    : ut_nn_inet_pton
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_inet_pton(void)
{
    
//    static int nn_inet_pton(int family, const char *src, void *dst);
    
}

/*============================================
* FuncName    : ut_nn_literal_resolve
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_literal_resolve(void)
{

    const char *addr = "127.0.0.1";
    size_t addrlen = strlen(addr);
    int ipv4only = TRUE;
    struct sockaddr_storage result;
    size_t resultlen = 0;
    
    int ulret = nn_literal_resolve (addr, addrlen,
                ipv4only, &result, &resultlen);
    assert(0 == ulret);
    #ifndef NN_HAVE_WINDOWS
    assert(sizeof (struct sockaddr_in) == resultlen);
    assert(AF_INET == result.ss_family );
    assert(0x100007f == ((struct sockaddr_in*) &result)->sin_addr.s_addr);
    #endif

//ipv6 addr test
    addr = "CDCD:910A:2222:5498:8475:1111:3900:2020";
    addrlen = strlen(addr);
    ipv4only = FALSE;
//    struct sockaddr_storage result;
    resultlen = 0;
    
    ulret = nn_literal_resolve (addr, addrlen,
                ipv4only, &result, &resultlen);
    assert(0 == ulret);
#ifndef NN_HAVE_WINDOWS
    assert(sizeof (struct sockaddr_in6) == resultlen);
    assert(AF_INET6 == result.ss_family );
    assert(0xa91cdcd == ((struct sockaddr_in6*) 
    &result)->sin6_addr.__in6_u.__u6_addr32[0]);
    assert(0x98542222 == ((struct sockaddr_in6*) 
    &result)->sin6_addr.__in6_u.__u6_addr32[1]);
    assert(0x11117584 == ((struct sockaddr_in6*) 
    &result)->sin6_addr.__in6_u.__u6_addr32[2]);
    assert(0x20200039 == ((struct sockaddr_in6*) 
    &result)->sin6_addr.__in6_u.__u6_addr32[3]);
#endif


}

void test_literal(void)
{
     ut_nn_inet_pton();
     ut_nn_inet_pton();
     ut_nn_literal_resolve();
}




