#ifndef BTREE_H
#define BTREE_H


typedef struct mempool_s {
//    spinlock_t lock;
    int min_nr;		/* nr of elements at *elements */
    int curr_nr;		/* Current nr of elements at *elements */
    void **elements;

    void *pool_data;
//    mempool_alloc_t *alloc;
//    mempool_free_t *free;
//    wait_queue_head_t wait;
} mempool_t;

/**
 * struct btree_head - btree head
 *
 * @node: the first node in the tree
 * @mempool: mempool used for node allocations
 * @height: current of the tree
 */
struct btree_head {
    unsigned long *node;
    mempool_t *mempool;
    int height;
};

#endif // BTREE_H
