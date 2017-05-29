#include "ut_string.h"
#include "commonheaders.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "stringops.h"
#ifdef __cplusplus
}
#endif


/*============================================
* FuncName    : ut_skip_spaces
* Description :
* Author      :
* Time        : 2017-05-29
============================================*/
void ut_skip_spaces(void)
{

    const char *hellomsg = "   hello world";
    char *p = skip_spaces(hellomsg);
    if(!p)
    {
        return;
    }
    assert(0 == strcmp("hello world", p));
}



/*============================================
* FuncName    : ut_skip_arg
* Description :
* Author      :
* Time        : 2017-05-29
============================================*/
void ut_skip_arg(void)
{
    const char *cp = "    hello world  -f";
    const char *p = skip_arg(cp);
    if(!p)
    {
        return;
    }
//    printf("p :    %s   \n", p);
    assert(0 == strcmp(cp, p));


    cp = "hello world -b";
    p = skip_arg(cp);
    if(!p)
    {
        return;
    }
    assert(0 == strcmp(" world -b", p));


//    assert(strncmp());

}






void test_string()
{
    ut_skip_spaces();
    ut_skip_arg();
}



