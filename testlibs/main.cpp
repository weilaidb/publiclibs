#include <iostream>

//for unittest
#include "ut_argv_split.h"
#include "ut_string.h"

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
    test_argv_split_funcs();
    test_string();
    cout << "Hello World!" << endl;
    return 0;
}

