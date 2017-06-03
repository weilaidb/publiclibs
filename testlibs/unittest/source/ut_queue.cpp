#include "commonheaders.h"
#include "defines.h"
#ifdef __cplusplus 
extern "C" {
#endif
#include "queue.h"
#ifdef __cplusplus 
}
#endif


/*============================================
* FuncName    : ut_nn_queue_init
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_queue_init(void)
{
    struct nn_queue self;
    nn_queue_init (&self);
    assert(NULL == self.head);
    assert(NULL == self.tail);
    
}

/*============================================
* FuncName    : ut_nn_queue_term
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_queue_term(void)
{
    struct nn_queue self;
    nn_queue_term (&self);
    assert(NULL == self.head);
    assert(NULL == self.tail);
}

/*============================================
* FuncName    : ut_nn_queue_empty
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_queue_empty(void)
{
    struct nn_queue self;
    nn_queue_init(&self);
    int empty = nn_queue_empty (&self);
    assert(TRUE == empty);
    
}

/*============================================
* FuncName    : ut_nn_queue_push
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_queue_push(void)
{
    struct nn_queue self;
    struct nn_queue_item item;
    item.next = NULL;
    nn_queue_init(&self);
    nn_queue_item_init(&item);
    int empty = nn_queue_empty (&self);
    assert(TRUE == empty);

    nn_queue_push (&self, &item);
    empty = nn_queue_empty (&self);
    assert(FALSE == empty);
}

/*============================================
* FuncName    : ut_nn_queue_remove
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_queue_remove(void)
{
    struct nn_queue self;
    struct nn_queue_item item;
    item.next = NULL;
    nn_queue_init(&self);
    nn_queue_item_init(&item);
    int empty = nn_queue_empty (&self);
    assert(TRUE == empty);

    nn_queue_push (&self, &item);
    empty = nn_queue_empty (&self);
    assert(FALSE == empty);

    
    nn_queue_remove (&self, &item);
    empty = nn_queue_empty (&self);
    assert(TRUE == empty);

}

/*============================================
* FuncName    : ut_nn_queue_pop
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_queue_pop(void)
{
    struct nn_queue self;
    struct nn_queue_item item;
    struct nn_queue_item item2;
    item.next = NULL;
    nn_queue_init(&self);
    nn_queue_item_init(&item);
    nn_queue_item_init(&item2);
    int empty = nn_queue_empty (&self);
    assert(TRUE == empty);

    nn_queue_push (&self, &item);
    nn_queue_push (&self, &item2);
    empty = nn_queue_empty (&self);
    assert(FALSE == empty);
    

    struct nn_queue_item * pitem = NULL;
    pitem = nn_queue_pop (&self);
    assert(&item == pitem);
    pitem = nn_queue_pop (&self);
    assert(&item2 == pitem);
    empty = nn_queue_empty (&self);
    assert(TRUE == empty);

}

/*============================================
* FuncName    : ut_nn_queue_item_init
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_queue_item_init(void)
{
    struct nn_queue_item self;
    nn_queue_item_init (&self);
    assert(NN_QUEUE_NOTINQUEUE == self.next);
    
}

/*============================================
* FuncName    : ut_nn_queue_item_term
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_queue_item_term(void)
{
    struct nn_queue_item self;
    nn_queue_item_term (&self);
    assert(NN_QUEUE_NOTINQUEUE == self.next);
    
}

/*============================================
* FuncName    : ut_nn_queue_item_isinqueue
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_queue_item_isinqueue(void)
{
    struct nn_queue_item self;
    nn_queue_item_init (&self);
    int inq = nn_queue_item_isinqueue (&self);
    assert(FALSE == inq);
    /* have elements */
    self.next = &self;
    inq = nn_queue_item_isinqueue (&self);
    assert(TRUE == inq);

}

void test_queue(void)
{
    ut_nn_queue_init();
    ut_nn_queue_term();
    ut_nn_queue_empty();
    ut_nn_queue_push();
    ut_nn_queue_remove();
    ut_nn_queue_pop();
    ut_nn_queue_item_init();
    ut_nn_queue_item_term();
    ut_nn_queue_item_isinqueue();

}
