#ifndef _UTILS_H_
#define _UTILS_H_
#include <climits>
#include <cstdint>
#include <cstdlib>
#include <random>
using namespace std;
template <typename T>
T get_rand (int minNum = 0, int maxNum = INT_MAX) {
#ifdef __linux__
    random_device rd;
    mt19937 eng (rd ());
    uniform_int_distribution<T> distr (minNum, maxNum);
    return distr (eng);
#else
    return rand () % (maxNum - minNum) + minNum;
#endif
}
template <typename T>
T get_rand_real (int minNum = 0, int maxNum = INT_MAX) {
    random_device rd;
    mt19937 eng (rd ());
    uniform_real_distribution<T> distr (minNum, maxNum);
    return distr (eng);
}
#endif