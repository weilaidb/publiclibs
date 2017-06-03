#include "commonheaders.h"
#include "defines.h"
#include "attr.h"
#ifdef __cplusplus 
extern "C" {
#endif
#include "lists.h"
#ifdef __cplusplus 
}
#endif


/*============================================
* FuncName    : ut_nn_list_init
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_list_init(void)
{
    struct nn_list self;
    nn_list_init (&self);
    assert(NULL == self.first);
    assert(NULL == self.last);

    
}

/*============================================
* FuncName    : ut_nn_list_term
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_list_term(void)
{
    struct nn_list self;
    nn_list_term (&self);
    assert(NULL == self.first);
    assert(NULL == self.last);
    
}

/*============================================
* FuncName    : ut_nn_list_empty
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_list_empty(void)
{
    struct nn_list self;
    nn_list_init (&self);
    int empty = nn_list_empty (&self);
    assert(TRUE == empty);
    
}

/*============================================
* FuncName    : ut_nn_list_begin
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_list_begin(void)
{
    struct nn_list self;
    nn_list_init (&self);

    struct nn_list_item *pbegin = NULL;
    pbegin = nn_list_begin (&self);
    assert(NULL == pbegin);

    

    
}

/*============================================
* FuncName    : ut_nn_list_end
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_list_end(void)
{
    NN_UNUSED struct nn_list self;
    nn_list_init (&self);

    struct nn_list_item *pbegin = NULL;

    pbegin = nn_list_end (&self);
    assert(NULL == pbegin);
    
}

/*============================================
* FuncName    : ut_nn_list_prev
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_list_prev(void)
{
    
    struct nn_list_item *nn_list_prev (struct nn_list *self,
    struct nn_list_item *it);
    
}


/*============================================
* FuncName    : ut_nn_list_next
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_list_next(void)
{
    struct nn_list_item * it = NULL;

    struct nn_list self;
    nn_list_init (&self);
    struct nn_list_item item1;
    struct nn_list_item item2;
    struct nn_list_item item3;

    nn_list_item_init(&item1);
    nn_list_item_init(&item2);
    nn_list_item_init(&item3);

    nn_list_insert(&self,&item1, it);
    nn_list_insert(&self,&item2, it);
    nn_list_insert(&self,&item3, it);

    struct nn_list_item *plist = nn_list_next (&self, &item2);
    assert(plist == &item3);
    
}


/*============================================
* FuncName    : ut_nn_list_insert
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_list_insert(void)
{
    struct nn_list_item * it = NULL;

    struct nn_list self;
    nn_list_init (&self);
    struct nn_list_item item1;
    struct nn_list_item item2;
    struct nn_list_item item3;

    nn_list_item_init(&item1);
    nn_list_item_init(&item2);
    nn_list_item_init(&item3);

    nn_list_insert(&self,&item1, it);
    nn_list_insert(&self,&item2, it);
    nn_list_insert(&self,&item3, it);
    

    void nn_list_insert (struct nn_list *self, struct nn_list_item *item,
    struct nn_list_item *it);
    
}


/*============================================
* FuncName    : ut_nn_list_erase
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_list_erase(void)
{
    struct nn_list_item * it = NULL;

    struct nn_list self;
    nn_list_init (&self);
    struct nn_list_item item1;
    struct nn_list_item item2;
    struct nn_list_item item3;

    nn_list_item_init(&item1);
    nn_list_item_init(&item2);
    nn_list_item_init(&item3);

    nn_list_insert(&self,&item1, it);
    struct nn_list_item *plist = nn_list_erase (&self, &item1);
    assert(NULL == plist);

    nn_list_insert(&self,&item1, it);
    nn_list_insert(&self,&item2, it);
    nn_list_insert(&self,&item3, it);

    plist = nn_list_erase (&self, &item2);
    assert(&item3 == plist);    
}


/*============================================
* FuncName    : ut_nn_list_item_init
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_list_item_init(void)
{
    struct nn_list_item self;
    nn_list_item_init (&self);
    assert(NN_LIST_NOTINLIST == self.prev);
    assert(NN_LIST_NOTINLIST == self.next);

}

/*============================================
* FuncName    : ut_nn_list_item_term
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_list_item_term(void)
{
    struct nn_list_item self;
    nn_list_item_init (&self);
    nn_list_item_term (&self);
    assert(NN_LIST_NOTINLIST == self.prev);
    assert(NN_LIST_NOTINLIST == self.next);
    
}

/*============================================
* FuncName    : ut_nn_list_item_isinlist
* Description : 
* Author      : 
* Time        : 2017-06-04
============================================*/
void ut_nn_list_item_isinlist(void)
{
    struct nn_list_item self;
    nn_list_item_init (&self);

    int inlist = nn_list_item_isinlist (&self);
    assert(FALSE == inlist);

}


void test_lists(void)
{
    ut_nn_list_init();
    ut_nn_list_term();
    ut_nn_list_empty();
    ut_nn_list_begin();
    ut_nn_list_end();
    ut_nn_list_prev();
    ut_nn_list_next();
    ut_nn_list_insert();
    ut_nn_list_erase();
    ut_nn_list_item_init();
    ut_nn_list_item_term();
    ut_nn_list_item_isinlist();

}


