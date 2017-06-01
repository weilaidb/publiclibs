#include "ut_chunk.h"

#include "commonheaders.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "chunk.h"
//#include "alloc.h"
#ifdef __cplusplus
}
#endif

/*============================================
* FuncName    : ut_nn_chunk_alloc
* Description :
* Author      :
* Time        : 2017-06-01
============================================*/
void ut_nn_chunk_alloc(void)
{
    int err = 0;
    size_t size = 1000;
    int type = 0;
    uint8_t *result = NULL;
    //返回地址result为标签后处地址
    err = nn_chunk_alloc (size, type, (void **)&result);
    assert(0 == err);
    assert(NULL != result);
    nn_chunk_free(result); //指定接口释放


    type = 1;
    result = NULL;
    err = nn_chunk_alloc (size, type, (void **)&result);
    assert(-EINVAL == err);
    assert(NULL == result);

    size = ~0;
    type = 0;
    result = NULL;
    err = nn_chunk_alloc (size, type, (void **)&result);
    assert(-ENOMEM == err);
    assert(NULL == result);

}

/*============================================
* FuncName    : ut_nn_chunk_realloc
* Description :
* Author      :
* Time        : 2017-06-01
============================================*/
void ut_nn_chunk_realloc(void)
{
    int err = 0;
    size_t size = 1000;
    int type = 0;
    uint8_t *chunk = NULL;
    //返回地址chunk为标签后处地址
    err = nn_chunk_alloc (size, type, (void **)&chunk);
    assert(0 == err);
    assert(NULL != chunk);
    size = 10000;
    err = nn_chunk_realloc (size, (void **)&chunk);
    assert(0 == err);
    assert(NULL != chunk);
    nn_chunk_free(chunk); //指定接口释放
}

/*============================================
* FuncName    : ut_nn_chunk_free
* Description :
* Author      :
* Time        : 2017-06-01
============================================*/
void ut_nn_chunk_free(void)
{
    int err = 0;
    size_t size = 100000;
    int type = 0;
    uint8_t *chunk = NULL;
    //返回地址chunk为标签后处地址
    err = nn_chunk_alloc (size, type, (void **)&chunk);
    assert(0 == err);
    assert(NULL != chunk);
    nn_chunk_free(chunk); //指定接口释放

}

/*============================================
* FuncName    : ut_nn_chunk_addref
* Description :
* Author      :
* Time        : 2017-06-01
============================================*/
void ut_nn_chunk_addref(void)
{
    int err = 0;
    size_t size = 100000;
    int type = 0;
    uint8_t *chunk = NULL;
    //返回地址chunk为标签后处地址
    err = nn_chunk_alloc (size, type, (void **)&chunk);
    assert(0 == err);
    assert(NULL != chunk);
    uint32_t n = 100;
    nn_chunk_addref (chunk, n);

//    struct nn_chunk *self;

//    self = nn_chunk_getptr (chunk);
//    assert(100 + 1 == self->refcount.n);

    nn_chunk_free(chunk); //指定接口释放
}

/*============================================
* FuncName    : ut_nn_chunk_size
* Description :
* Author      :
* Time        : 2017-06-01
============================================*/
void ut_nn_chunk_size(void)
{
    int err = 0;
    size_t size = 100000;
    int type = 0;
    uint8_t *chunk = NULL;
    //返回地址chunk为标签后处地址
    err = nn_chunk_alloc (size, type, (void **)&chunk);
    assert(0 == err);
    assert(NULL != chunk);

    size = nn_chunk_size (chunk);
    assert(100000 == size);
    nn_chunk_free(chunk);

}

/*============================================
* FuncName    : ut_nn_chunk_trim
* Description :
* Author      :
* Time        : 2017-06-01
============================================*/
void ut_nn_chunk_trim(void)
{
    int err = 0;
    size_t size = 100000;
    int type = 0;
    uint8_t *chunk = NULL;
    //返回地址chunk为标签后处地址
    err = nn_chunk_alloc (size, type, (void **)&chunk);
    assert(0 == err);
    assert(NULL != chunk);

    size = nn_chunk_size (chunk);
    assert(100000 == size);
    int subnum = 10000 ;
    nn_chunk_trim (chunk, subnum);
    size = nn_chunk_size (chunk);
    assert(90000 == size);
    nn_chunk_free(chunk);

}



void test_chunk(void)
{
    ut_nn_chunk_alloc();
    ut_nn_chunk_realloc();
    ut_nn_chunk_free();
    ut_nn_chunk_addref();
    ut_nn_chunk_size();
    ut_nn_chunk_trim();

}
