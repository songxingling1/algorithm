#ifndef _UTILS_H_
#define _UTILS_H_
#include <cstdint>
#include <random>
int get_rand(int minNum = 0, int maxNum = INT32_MAX);
int get_rand(int minNum, int maxNum) {
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<int> distr(minNum,
                                        maxNum);
    return distr(eng);
}
#endif