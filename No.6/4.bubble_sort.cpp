#include <cstdio>
#include <iostream>
#include "libSortTest.h"
using namespace std;
void bubble_sort(int* arr, int left, int right) {
    bool flag;
    for(int i = right - 1; i >= left + 1; i--) {
        flag = true;
        for(int j = left; j < i; j++) {
            if(arr[j] <= arr[j + 1])
                continue;
            swap(arr[j], arr[j + 1]);
            flag = false;
        }
        if(flag)
            break;
    }
}
int main() {
    init_rand();
    int* arr = get_rand_data(SMALL_DATA_N);
    TEST(bubble_sort, arr, SMALL_DATA_N);
    delete[] arr;
    return 0;
}