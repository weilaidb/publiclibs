#include <assert.h>
#include "ut_argv_split.h"
#include "typedefs.h"
//#include "defines.h"

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
