#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "ut_argv_split.h"
//#include "typedefs.h"
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

void artv_split_funcs()
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
    char *tmp = (char *)malloc(sizeof(char) * 10);
    char **argv = &tmp;
    memset(*argv, 0, sizeof(sizeof(char) * 10));
    assert(argv != NULL);
    argv_free(argv);
    free(tmp);
//    delete [] tmp;
}

void ut_malloc_free()
{
    char *tmp = (char *)malloc(10);
    assert(tmp != NULL);
    free(tmp);
}




