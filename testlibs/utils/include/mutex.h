#ifndef MUTEX_H
#define MUTEX_H



#ifdef NN_HAVE_WINDOWS
#include "wins.h"
#else
#include <pthread.h>
#endif

struct nn_mutex {
    /*  NB: The fields of this structure are private to the mutex
        implementation. */
#ifdef NN_HAVE_WINDOWS
    CRITICAL_SECTION cs;
    DWORD owner;
    int debug;
#else
    pthread_mutex_t mutex;
#endif
};

typedef struct nn_mutex nn_mutex_t;

/*  Initialise the mutex. */
void nn_mutex_init (nn_mutex_t *self);

/*  Terminate the mutex. */
void nn_mutex_term (nn_mutex_t *self);

/*  Lock the mutex. Behaviour of multiple locks from the same thread is
    undefined. */
void nn_mutex_lock (nn_mutex_t *self);

/*  Unlock the mutex. Behaviour of unlocking an unlocked mutex is undefined */
void nn_mutex_unlock (nn_mutex_t *self);

#endif // MUTEX_H
