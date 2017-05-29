#include "string.h"
#include "commonheaders.h"


/**
 * skip_spaces - Removes leading whitespace from @str.
 * @str: The string to be stripped.
 *
 * Returns a pointer to the first non-whitespace character in @str.
 */
/*============================================
* FuncName    : skip_spaces
* Description :获取开始处不带空白的字符串
* @str        :开头带字符或不带空白符的字符串
* Author      :
* Time        : 2017-05-29
============================================*/
char *skip_spaces(const char *str)
{
    while (isspace(*str))
        ++str;
    return (char *)str;
}

/*============================================
* FuncName    : skip_arg
* Description : 跳过第一个不是空格的参数
* @cp         : "a b c" 返回" b c"
* Author      :
* Time        : 2017-05-29
============================================*/
const char *skip_arg(const char *cp)
{
    while (*cp && !isspace(*cp))
        cp++;

    return cp;
}

