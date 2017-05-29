#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ut_argv_split.h"
#include "typedefs.h"
#include "defines.h"
#ifdef __WIN32__
#include <windows.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif
#include "argv_split.h"

#ifdef __cplusplus
}
#endif



ut_argv_split::ut_argv_split()
{
}



void ut_count_argc()
{
    const char *argv = "a good     things";
    int count = count_argc(argv);
    assert(count == 3);
}

void ut_argv_free()
{
    const WORD32 memcount = 1000;
    char **argv = (char **)malloc(sizeof(char *) * (memcount + 1)); // need add one more.
    int i = 0;
    for(i = 0; i < memcount; i++)
    {
        argv[i] = (char *)malloc(100);
    }
    argv[i] = NULL; //need add

    memset(*argv, 0, sizeof(sizeof(char) * 10));
    assert(argv != NULL);

#ifdef __WIN32__
//    Sleep(1000);
#else
//    sleep(1);
#endif

    argv_free(&argv);
    assert(argv == NULL);

    argv_free(&argv);
}

void ut_malloc_free()
{
    char *tmp = (char *)malloc(10);
    assert(tmp != NULL);
    free(tmp);
    tmp = NULL;
    assert(tmp == NULL);
    free(tmp);

}


/*============================================
* FuncName    : ut_argv_split
* Description :
* Author      :
* Time        : 2017-05-29
============================================*/
void ut_argv_split(void)
{

    const char *s = " first second third fourth 1 2 3 ";
    int argcp = 0;
    char **p = argv_split(s, &argcp);
    assert(argcp == 7);

    assert(0 == strncmp(p[0],"first", strlen("first")));
    assert(0 == strncmp(p[1],"second", strlen("second")));
    assert(0 == strncmp(p[2],"third", strlen("third")));
    assert(0 == strncmp(p[3],"fourth", strlen("fourth")));
    assert(0 == strncmp(p[4],"1", strlen("1")));
    assert(0 == strncmp(p[5],"2", strlen("2")));
    assert(0 == strncmp(p[6],"3", strlen("3")));

    argv_free(&p);

}




void test_argv_split_funcs()
{
    ut_count_argc();
    ut_argv_free();
    ut_malloc_free();
    ut_argv_split();
}

