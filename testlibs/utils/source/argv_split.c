/*
 * Helper function for splitting a string into an argv-like array.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "typedefs.h"
#include "defines.h"

/*============================================
* FuncName    : count_argc
* Description : str以空格分隔的数据个数
* @str        : 字符串
* Author      :
* Time        : 2017-05-28
============================================*/
int count_argc(const char *str)
{
    int count = 0;
    bool was_space;

    for (was_space = true; *str; str++) {
        if (isspace(*str)) {
            was_space = true;
        } else if (was_space) {
            was_space = false;
            count++;
        }
    }

    return count;
}

/**
 * argv_free - free an argv
 * @argv - the argument vector to be freed
 *
 * Frees an argv and the strings it points to.
 */
/*============================================
* FuncName    : argv_free
* Description :
* @argv       :
* Author      :
* Time        : 2017-05-29
============================================*/
void argv_free(char ***argv)
{
    char **p;
    if(!argv || !*argv)
    {
        return;
    }
    for (p = *argv; *p; p++)
    {
        free(*p);
        *p = NULL;
    }

    free(*argv);
    *argv = NULL;
}


/**
 * argv_split - split a string at whitespace, returning an argv
 * @gfp: the GFP mask used to allocate memory
 * @str: the string to be split
 * @argcp: returned argument count
 *
 * Returns an array of pointers to strings which are split out from
 * @str.  This is performed by strictly splitting on white-space; no
 * quote processing is performed.  Multiple whitespace characters are
 * considered to be a single argument separator.  The returned array
 * is always NULL-terminated.  Returns NULL on memory allocation
 * failure.
 */
/*============================================
* FuncName    : argv_split
* Description :
* @gfp        :
* @str        :
* @argcp      :
* Author      :
* Time        : 2017-05-29
============================================*/
char **argv_split(const char *str, int *argcp)
{
    int argc = count_argc(str);
    char **argv = (char **)malloc(sizeof(*argv) * (argc+1));
    char **argvp;

    if (argv == NULL)
        goto out;

    if (argcp)
        *argcp = argc;

    argvp = argv;

    while (*str) {
        str = skip_spaces(str);

        if (*str) {
            const char *p = str;
            char *t;

            str = skip_arg(str);

            t = (char *)malloc(str - p + 1);
            if (t == NULL)
                goto fail;
            memset(t, 0, str - p + 1);
            memcpy(t, p, str - p + 1);
            t[str - p + 1] = '\0';
            *argvp++ = t;
        }
    }
    *argvp = NULL;

  out:
    return argv;

  fail:
    argv_free(argv);
    return NULL;
}

