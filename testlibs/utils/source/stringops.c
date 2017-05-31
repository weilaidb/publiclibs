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
* Description :��ȡ��ʼ�������հ׵��ַ���
* @str        :��ͷ���ַ��򲻴��հ׷����ַ���
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
* Description : ������һ�����ǿո�Ĳ���
* @cp         : "a b c" ����" b c"
* Author      :
* Time        : 2017-05-29
============================================*/
const char *skip_arg(const char *cp)
{
    while (*cp && !isspace(*cp))
        cp++;

    return cp;
}

