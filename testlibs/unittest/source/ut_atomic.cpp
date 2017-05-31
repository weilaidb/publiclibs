#include "ut_atomic.h"
#include "commonheaders.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "atomic.h"
#ifdef __cplusplus
}
#endif

ut_atomic::ut_atomic()
{
}


/*============================================
* FuncName    : ut_nn_atomic_init
* Description :
* Author      :
* Time        : 2017-06-01
============================================*/
void ut_nn_atomic_init(void)
{

    struct nn_atomic self = {0};
    uint32_t n = 10;
    nn_atomic_init (&self, n);
    assert(10 == n);
}

/*============================================
* FuncName    : ut_nn_atomic_term
* Description :
* Author      :
* Time        : 2017-06-01
============================================*/
void ut_nn_atomic_term(void)
{
    struct nn_atomic self = {0};
    uint32_t n = 10;
    nn_atomic_term (&self);

}

/*============================================
* FuncName    : ut_nn_atomic_inc
* Description :
* Author      :
* Time        : 2017-06-01
============================================*/
void ut_nn_atomic_inc(void)
{
    struct nn_atomic self = {0};
    uint32_t n = 10;
    nn_atomic_init (&self, n);
    nn_atomic_inc (&self, n);
    assert(20== self.n);

}

/*============================================
* FuncName    : ut_nn_atomic_dec
* Description :
* Author      :
* Time        : 2017-06-01
============================================*/
void ut_nn_atomic_dec(void)
{
    struct nn_atomic self = {0};
    uint32_t n = 10;
    nn_atomic_init (&self, n);
    n  = 5;
    nn_atomic_dec (&self, n);
    assert(5== self.n);

}



void test_atomic()
{
    ut_nn_atomic_init();
    ut_nn_atomic_term();
    ut_nn_atomic_inc();
    ut_nn_atomic_dec();

}
