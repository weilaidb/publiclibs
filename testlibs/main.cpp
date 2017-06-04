#include <iostream>
#include "version.h"
//for unittest
#include "ut_argv_split.h"
#include "ut_string.h"
#include "ut_list.h"
#include "ut_log.h"
#include "ut_alloc.h"
#include "ut_mutex.h"
#include "ut_atomic.h"
#include "ut_wire.h"
#include "ut_chunk.h"
#include "ut_queue.h"
#include "ut_lists.h"
#include "ut_literal.h"

/*

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif*/


using namespace std;

int main()
{
    cout << "==Ver: " << version  << "==="<< endl;

    test_argv_split_funcs();
    test_string();
    test_list();
    test_log();
    test_alloc();
    test_mutex();
    test_atomic();
    test_wire();
    test_chunk();
    test_queue();
    test_lists();
    test_literal();

    cout << "Hello World! My Love Baby!!!" << endl;
    return 0;
}

