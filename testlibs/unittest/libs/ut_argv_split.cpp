#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ut_argv_split.h"
#include "typedefs.h"
#include "defines.h"

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

void test_argv_split_funcs()
{
    ut_count_argc();
    ut_argv_free();
    ut_malloc_free();
}


void ut_count_argc()
{
    const char *argv = "a good     things";
    int count = count_argc(argv);
    assert(count == 3);
}

void ut_argv_free()
{
    const WORD32 memcount = 100000;
    char **argv = (char **)malloc(sizeof(char *) * memcount);
    int i = 0;
    for(i = 0; i < memcount; i++)
    {
        argv[i] = (char *)malloc(100);
    }

    memset(*argv, 0, sizeof(sizeof(char) * 10));
    assert(argv != NULL);

#ifdef __WIN32__
    Sleep(10000);
#else
    sleep(10);
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




