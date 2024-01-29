#include <cstdio>
#include <iostream>
#include "libSortTest.h"
#define K 65536
using namespace std;
void radix_sort(int* arr, int left, int right) {
    int* cnt = new int[K + 5];
    int* temp = new int[right - left];
    memset(cnt, 0, sizeof(int) * K + 5);
    // round 1
    for(int i = left; i < right; i++)
        cnt[arr[i] % K]++;
    for(int i = 1; i < K; i++)
        cnt[i] += cnt[i - 1];
    for(int i = right - 1; i >= left; i--)
        temp[--cnt[arr[i] % K]] = arr[i];
    memcpy(arr + left, temp,
           sizeof(int) * (right - left));
    // round 2
    memset(cnt, 0, sizeof(int) * K + 5);
    for(int i = left; i < right; i++)
        cnt[arr[i] / K]++;
    for(int i = 1; i < K; i++)
        cnt[i] += cnt[i - 1];
    for(int i = right - 1; i >= left; i--)
        temp[--cnt[arr[i] / K]] = arr[i];
    memcpy(arr + left, temp,
           sizeof(int) * (right - left));
}
int main() {
    init_rand();
    int* arrS = get_rand_data(SMALL_DATA_N);
    int* arrB = get_rand_data(BIG_DATA_N);
    TEST(radix_sort, arrS, SMALL_DATA_N);
    TEST(radix_sort, arrB, BIG_DATA_N);
    delete[] arrS;
    delete[] arrB;
    return 0;
}