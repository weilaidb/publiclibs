#include "ut_chunkref.h"


#ifdef __cplusplus
extern "C" {
#endif
#include "commonheaders.h"

#include "chunkref.h"
//#include "alloc.h"
#ifdef __cplusplus
}
#endif



/*============================================
* FuncName    : ut_nn_chunkref_init
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_chunkref_init(void)
{
    struct nn_chunkref self;
    size_t size = 100;
    nn_chunkref_init (&self, size);
    assert(0xFF == *((uint8_t *)&self));
    assert(NULL != ((uint8_t *)&self) + 1);    
}

/*============================================
* FuncName    : ut_nn_chunkref_init_chunk
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_chunkref_init_chunk(void)
{
    struct nn_chunkref self;
    void *chunk = (void *)malloc(1024);
    if(!chunk) return;
    nn_chunkref_init_chunk (&self, chunk);
    assert(0xFF == *((uint8_t *)&self));
    assert(NULL != ((uint8_t *)&self) + 1); 
    struct nn_chunkref *pt = &self;
    assert(chunk == (void *)*(((uint32_t *)((uint8_t *)pt + 1)))); 
    assert(chunk == (void *)*((uint32_t *)((uint8_t *)&self + 1)));
    free(chunk);
}

/*============================================
* FuncName    : ut_nn_chunkref_term
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_chunkref_term(void)
{
    struct nn_chunkref self;
    memset(&self, 0, sizeof(self));
    void *chunk = (void *)malloc(1024);
    if(!chunk) return;
    size_t size = 1024;
    nn_chunkref_init(&self,size);
//    nn_chunkref_init_chunk(&self, chunk);
    assert(0xFF == *((uint8_t *)&self));
    assert(NULL != ((uint8_t *)&self) + 1); 
//     *(uint32_t *)(((uint8_t *)&self) + 1) = 0x10; // why here??
    nn_chunkref_term (&self);
    assert(0xFF == *((uint8_t *)&self));
    assert(NULL != ((uint8_t *)&self) + 1); 

    free(chunk);

}

/*============================================
* FuncName    : ut_nn_chunkref_getchunk
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_chunkref_getchunk(void)
{
    struct nn_chunkref self;
    memset(&self, 0, sizeof(self));
    void *chunk = (void *)malloc(1024);
    if(!chunk) return;
    size_t size = 1024;
    nn_chunkref_init(&self,size);
    mlogmsg_byfunc(&self, sizeof(self), "self");
    assert(0xFF == *((uint8_t *)&self));
    assert(NULL != ((uint8_t *)&self) + 1); 
    
    void * pchunk = nn_chunkref_getchunk (&self);
    mlog_byfunc("pchunk:%p", pchunk);
    mlog_byfunc("self:%p", self);
    mlog_byfunc("&self:%p", &self);

    mlog_byfunc("(void *)((uint8_t *)&self) + 1:%p", (void *)((uint8_t *)&self) + 1);
    mlog_byfunc("(void *)((uint8_t *)&self + 1):%p", (void *)((uint8_t *)&self + 1) );
    mlog_byfunc("*(unsigned int *)((uint8_t *)&self + 1):%p", *(unsigned int *)((uint8_t *)&self + 1) );
    mlog_byfunc("(void *)((uint8_t *)self + 1):%p", (void *)((uint8_t *)&self + 1) );
    mlogmsg_byfunc(&self, sizeof(self), "self");
    showmlogkeys();
    
    void *pcompare = (void *)(*(unsigned int *)((uint8_t *)&self + 1));
    assert(pchunk ==  pcompare);


//    mlog_byfunc("&self:%p", &self);
    mlogmsg_byfunc(&self, sizeof(self), "self");
    showmlog_byfunc;

    nn_chunkref_term (&self);
    assert(0x0 == *((uint8_t *)&self));
    assert(NULL != ((uint8_t *)&self) + 1); 

    free(chunk);
    
    
}

/*============================================
* FuncName    : ut_nn_chunkref_mv
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_chunkref_mv(void)
{
    
    void nn_chunkref_mv (struct nn_chunkref *dst, struct nn_chunkref *src);
    
}

/*============================================
* FuncName    : ut_nn_chunkref_cp
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_chunkref_cp(void)
{
    
    void nn_chunkref_cp (struct nn_chunkref *dst, struct nn_chunkref *src);
    
}

/*============================================
* FuncName    : ut_nn_chunkref_data
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_chunkref_data(void)
{
    
    void *nn_chunkref_data (struct nn_chunkref *self);
    
}

/*============================================
* FuncName    : ut_nn_chunkref_size
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_chunkref_size(void)
{
    
    size_t nn_chunkref_size (struct nn_chunkref *self);
    
}

/*============================================
* FuncName    : ut_nn_chunkref_trim
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_chunkref_trim(void)
{
    
    void nn_chunkref_trim (struct nn_chunkref *self, size_t n);
    
}

/*============================================
* FuncName    : ut_nn_chunkref_bulkcopy_start
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_chunkref_bulkcopy_start(void)
{
    
    void nn_chunkref_bulkcopy_start (struct nn_chunkref *self, uint32_t copies
);
    
}

/*============================================
* FuncName    : ut_nn_chunkref_bulkcopy_cp
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_chunkref_bulkcopy_cp(void)
{
    
    void nn_chunkref_bulkcopy_cp (struct nn_chunkref *dst, struct nn_chunkref 
*src);
    
}

void test_chunkref()
{
    ut_nn_chunkref_init();
    ut_nn_chunkref_init_chunk();
    ut_nn_chunkref_term();
    ut_nn_chunkref_getchunk();
    ut_nn_chunkref_mv();
    ut_nn_chunkref_cp();
    ut_nn_chunkref_data();
    ut_nn_chunkref_size();
    ut_nn_chunkref_trim();
    ut_nn_chunkref_bulkcopy_start();
    ut_nn_chunkref_bulkcopy_cp();
}
