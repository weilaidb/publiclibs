#include "slab.h"

/**
 * kmem_cache_alloc - Allocate an object
 * @cachep: The cache to allocate from.
 * @flags: See kmalloc().
 *
 * Allocate an object from this cache.  The flags are only relevant
 * if the cache has no available objects.
 */
/*============================================
* FuncName    : kmem_cache_alloc
* Description :
* @cachep     :
* @flags      :
* Author      :
* Time        : 2017-05-30
============================================*/
void *kmem_cache_alloc(struct kmem_cache *cachep)
{
    void *ret = (void *)malloc(cachep);

//    trace_kmem_cache_alloc(_RET_IP_, ret,
//                   cachep->object_size, cachep->size, flags);

    return ret;
}

/*============================================
* FuncName    : kmem_cache_free
* Description :
* @s          :
* @x          :
* Author      :
* Time        : 2017-05-30
============================================*/
void kmem_cache_free(struct kmem_cache *s, void *x)
{
//    s = cache_from_obj(s, x);
    if (!s)
        return;
    free(s);
//    trace_kmem_cache_free(_RET_IP_, x);
}
