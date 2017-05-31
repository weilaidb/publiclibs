#include "ut_alloc.h"
#include "commonheaders.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "alloc.h"
#ifdef __cplusplus
}
#endif



/*============================================
* FuncName    : ut_nn_alloc_init
* Description :
* Author      :
* Time        : 2017-05-31
============================================*/
void ut_nn_alloc_init(void)
{

    nn_alloc_init ();

}

/*============================================
* FuncName    : ut_nn_alloc_term
* Description :
* Author      :
* Time        : 2017-05-31
============================================*/
void ut_nn_alloc_term(void)
{

    nn_alloc_term ();

}

/*============================================
* FuncName    : ut_nn_alloc_
* Description :
* Author      :
* Time        : 2017-05-31
============================================*/
void ut_nn_alloc_(void)
{
    size_t size = 100;
    void * pbuf = nn_alloc_ (size);
    if(!pbuf)
        return;

    nn_free(pbuf);
}

/*============================================
* FuncName    : ut_nn_realloc
* Description :
* Author      :
* Time        : 2017-05-31
============================================*/
void ut_nn_realloc(void)
{
    size_t size = 100;
    void * ptr = nn_alloc_ (size);
    if(!ptr)
        return;

    size = 10000;
    ptr = nn_realloc (ptr, size);
    nn_free(ptr);

}

/*============================================
* FuncName    : ut_nn_free
* Description :
* Author      :
* Time        : 2017-05-31
============================================*/
void ut_nn_free(void)
{
    void *ptr = NULL;
    nn_free (ptr);

}


void test_alloc()
{
    ut_nn_alloc_init();
    ut_nn_alloc_term();
    ut_nn_alloc_();
    ut_nn_realloc();
    ut_nn_free();
}
