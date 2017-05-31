#include "ut_list.h"
#include "list.h"

ut_list::ut_list()
{
}


void ut_LIST_HEAD(void)
{
    LIST_HEAD(abc);
    assert(abc.next == &abc);
    assert(abc.prev == &abc);
}
void ut_INIT_LIST_HEAD(void)
{
    struct list_head list = {0};
    INIT_LIST_HEAD(&list);
    assert(list.next == &list);
    assert(list.prev == &list);
}

void ut__list_add(void)
{
    struct list_head list = {0};
    struct list_head listnew = {0};
    INIT_LIST_HEAD(&list);
    INIT_LIST_HEAD(&listnew);
    __list_add(&listnew, list.prev,
                  list.next);
}







/*============================================
* FuncName    : test_list
* Description :
* @           :
* Author      :
* Time        : 2017-05-30
============================================*/
void test_list()
{
    ut_LIST_HEAD();
    ut_INIT_LIST_HEAD();
    ut__list_add();
}


