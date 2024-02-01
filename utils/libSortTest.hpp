#ifndef _LIB_SORT_TEST_H_
#define _LIB_SORT_TEST_H_
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "tools.hpp"
#define SMALL_DATA_N 5000
#define BIG_DATA_N 100000
#define TEST(func, arr, n)                                           \
    {                                                                \
        printf ("Test %s : ", #func);                                \
        int* temp = new int[n];                                      \
        memcpy (temp, arr, sizeof (int) * (n));                      \
        long long begin = clock ();                                  \
        func (temp, 0, n);                                           \
        long long end = clock ();                                    \
        if (check (temp, 0, n)) {                                    \
            printf ("\tOK ");                                        \
        } else {                                                     \
            printf ("Failed ");                                      \
        }                                                            \
        printf (" %ditems %lld ms \n", n,                            \
                (end - begin) * 1000 / CLOCKS_PER_SEC);              \
        delete[] temp;                                               \
    }

bool check (const int* arr, int left, int right) {
    for (int i = left + 1; i < right; i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}
void init_rand () {
    printf ("init rand\n");
}
int* get_rand_data (int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = get_rand<int> (0, 10000);
    return arr;
}

#endif