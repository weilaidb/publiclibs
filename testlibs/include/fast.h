#ifndef FAST_H
#define FAST_H

//#if defined __GNUC__ || defined __llvm__
#if 0
#define nn_fast(x) __builtin_expect ((x), 1)
#define nn_slow(x) __builtin_expect ((x), 0)
#else
#define nn_fast(x) (x)
#define nn_slow(x) (x)
#endif

#endif // FAST_H
