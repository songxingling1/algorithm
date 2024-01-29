#include <cstdio>
#include <iostream>
#include "libSortTest.h"

int* gBuff;
void merge_sort(int* arr, int left, int right) {
    if(right - left <= 1)
        return;
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid, right);
    int pos1 = left, pos2 = mid, pos = 0;
    while(pos1 < mid || pos2 < right) {
        if(pos2 == right || (pos1 < mid && arr[pos1] <= arr[pos2])) {
            gBuff[pos++] = arr[pos1++];
        } else {
            gBuff[pos++] = arr[pos2++];
        }
    }
    for(int i = left; i < right; i++)
        arr[i] = gBuff[i - left];
}
using namespace std;
int main() {
    init_rand();
    int* arrS = get_rand_data(SMALL_DATA_N);
    int* arrB = get_rand_data(BIG_DATA_N);
    gBuff = new int[BIG_DATA_N];
    TEST(merge_sort, arrS, SMALL_DATA_N);
    TEST(merge_sort, arrB, BIG_DATA_N);
    delete[] arrS;
    delete[] arrB;
    delete[] gBuff;
    return 0;
}