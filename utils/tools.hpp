#ifndef _UTILS_H_
#define _UTILS_H_
#include <climits>
#include <cstdlib>
#include <random>
using namespace std;
random_device rd;
mt19937 eng(rd());
template<typename T>
T get_rand(int minNum = 0, int maxNum = INT_MAX) {
#ifdef __linux__
    uniform_int_distribution<T> distr(minNum, maxNum);
    return distr(eng);
#else
    return rand() % (maxNum - minNum) + minNum;
#endif
}
template<typename T>
T get_rand_real(int minNum = 0, int maxNum = INT_MAX) {
    uniform_real_distribution<T> distr(minNum, maxNum);
    return distr(eng);
}

void init_rand() {
    printf("init rand\n");
}
#endif