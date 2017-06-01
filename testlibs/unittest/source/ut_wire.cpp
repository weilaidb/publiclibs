#include "ut_wire.h"
#include "commonheaders.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "wire.h"
#ifdef __cplusplus
}
#endif



/*============================================
* FuncName    : ut_nn_gets
* Description :
* Author      :
* Time        : 2017-06-01
============================================*/
void ut_nn_gets(void)
{
    const uint8_t buf[10] =  {1,2,3,};

    uint16_t dig = nn_gets (buf);
    assert(dig == 0x102);

}

/*============================================
* FuncName    : ut_nn_puts
* Description :
* Author      :
* Time        : 2017-06-01
============================================*/
void ut_nn_puts(void)
{

    const uint8_t buf[10] =  {0};

    uint16_t val = 0x102;
    nn_puts ((uint8_t *)buf, val);
    assert(buf[0] == 1);
    assert(buf[1] == 2);

}

/*============================================
* FuncName    : ut_nn_getl
* Description :
* Author      :
* Time        : 2017-06-01
============================================*/
void ut_nn_getl(void)
{

    const uint8_t buf[10] =  {1,2,3,4,};
    uint32_t val = nn_getl (buf);
    assert(0x01020304 == val);

}

/*============================================
* FuncName    : ut_nn_putl
* Description :
* Author      :
* Time        : 2017-06-01
============================================*/
void ut_nn_putl(void)
{

    const uint8_t buf[10] =  {0};

    uint32_t val = 0xfefcfdfb;
    nn_putl ((uint8_t *)buf, val);
    assert(0xfe == buf[0]);
    assert(0xfc == buf[1]);
    assert(0xfd == buf[2]);
    assert(0xfb == buf[3]);

}

/*============================================
* FuncName    : ut_nn_getll
* Description :
* Author      :
* Time        : 2017-06-01
============================================*/
void ut_nn_getll(void)
{
    const uint8_t buf[10] =  {1,2,3,4,5,6,7,8,};
    uint64_t val = nn_getll (buf);
    assert(0x0102030405060708 == val);

}

/*============================================
* FuncName    : ut_nn_putll
* Description :
* Author      :
* Time        : 2017-06-01
============================================*/
void ut_nn_putll(void)
{
    const uint8_t buf[10] =  {0};

    uint64_t val = 0xfefcfdfb;
    nn_putll ((uint8_t *)buf, val);
    assert(0 == buf[0]);
    assert(0 == buf[1]);
    assert(0 == buf[2]);
    assert(0 == buf[3]);
    assert(0xfe == buf[4]);
    assert(0xfc == buf[5]);
    assert(0xfd == buf[6]);
    assert(0xfb == buf[7]);

}


void test_wire()
{
    ut_nn_gets();
    ut_nn_puts();
    ut_nn_getl();
    ut_nn_putl();
    ut_nn_getll();
    ut_nn_putll();
}
