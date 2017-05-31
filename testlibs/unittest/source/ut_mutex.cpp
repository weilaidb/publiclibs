#include "ut_mutex.h"
#include "commonheaders.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "mutex.h"
#ifdef __cplusplus
}
#endif



/*============================================
* FuncName    : ut_nn_mutex_init
* Description :
* Author      :
* Time        : 2017-05-31
============================================*/
void ut_nn_mutex_init(void)
{
#ifdef NN_HAVE_WINDOWS
    nn_mutex_t self;
    nn_mutex_init (&self);
    assert(self.owner == 0);
#else
    nn_mutex_t self = {0};
    nn_mutex_init (&self);
    assert(self.mutex.__data.__count == 0/*PTHREAD_MUTEX_INITIALIZER*/);
    //locate pthreadtypes.h
#endif
}

/*============================================
* FuncName    : ut_nn_mutex_term
* Description :
* Author      :
* Time        : 2017-05-31
============================================*/
void ut_nn_mutex_term(void)
{
#ifdef NN_HAVE_WINDOWS
    nn_mutex_t self;
    nn_mutex_term (&self);
    nn_assert(self->owner == 0);
#else
    nn_mutex_t self;
    nn_mutex_term (&self);
    assert(self.mutex.__data.__count == 0/*PTHREAD_MUTEX_INITIALIZER*/);
#endif
}

/*============================================
* FuncName    : ut_nn_mutex_lock
* Description :
* Author      :
* Time        : 2017-05-31
============================================*/
void ut_nn_mutex_lock(void)
{

    void nn_mutex_lock (nn_mutex_t *self);

}

/*============================================
* FuncName    : ut_nn_mutex_unlock
* Description :
* Author      :
* Time        : 2017-05-31
============================================*/
void ut_nn_mutex_unlock(void)
{

    void nn_mutex_unlock (nn_mutex_t *self);

}


void test_mutex(void)
{
    ut_nn_mutex_init();
    ut_nn_mutex_term();
    ut_nn_mutex_lock();
    ut_nn_mutex_unlock();
}
