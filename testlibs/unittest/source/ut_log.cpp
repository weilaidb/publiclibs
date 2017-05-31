#include "ut_log.h"
#include "commonheaders.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "log.h"
#ifdef __cplusplus
}
#endif




/*============================================
* FuncName    : ut_check_color_terminal
* Description :
* Author      :
* Time        : 2017-05-30
============================================*/
void ut_check_color_terminal(void)
{

    check_color_terminal();
    assert(get_use_color() == 0);

}

/*============================================
* FuncName    : ut_set_use_color
* Description :
* Author      :
* Time        : 2017-05-30
============================================*/
void ut_set_use_color(void)
{

    set_use_color(1);
    assert(get_use_color() == 1);

}

/*============================================
* FuncName    : ut_get_use_color
* Description :
* Author      :
* Time        : 2017-05-30
============================================*/
void ut_get_use_color(void)
{

    get_use_color();
    assert(get_use_color() == 1);

}



void test_log()
{
    ut_check_color_terminal();
    ut_set_use_color();
    ut_get_use_color();
}
