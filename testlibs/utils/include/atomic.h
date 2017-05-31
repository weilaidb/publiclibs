#ifndef ATOMIC_H
#define ATOMIC_H


#if defined NN_HAVE_WINDOWS
#include "win.h"
#define NN_ATOMIC_WINAPI
#elif NN_HAVE_ATOMIC_SOLARIS
#include <atomic.h>
#define NN_ATOMIC_SOLARIS
#elif defined NN_HAVE_GCC_ATOMIC_BUILTINS
#define NN_ATOMIC_GCC_BUILTINS
#else
#include "mutex.h"
#define NN_ATOMIC_MUTEX
#endif

#include <stdint.h>

struct nn_atomic {
#if defined NN_ATOMIC_MUTEX
    struct nn_mutex sync;
#endif
    volatile uint32_t n;
};

/*  Initialise the object. Set it to value 'n'. */
void nn_atomic_init (struct nn_atomic *self, uint32_t n);

/*  Destroy the object. */
void nn_atomic_term (struct nn_atomic *self);

/*  Atomically add n to the object, return old value of the object. */
uint32_t nn_atomic_inc (struct nn_atomic *self, uint32_t n);

/*  Atomically subtract n from the object, return old value of the object. */
uint32_t nn_atomic_dec (struct nn_atomic *self, uint32_t n);


#endif // ATOMIC_H
