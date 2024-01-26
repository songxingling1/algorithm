#include <cstdio>
#include <iostream>
#include "libSortTest.h"
using namespace std;
void insert_sort(int* arr, int left, int right) {
    for(int i = left + 1; i < right; i++) {
        int numj = i;
        while(numj > left && arr[numj] < arr[numj - 1]) {
            swap(arr[numj], arr[numj - 1]);
            numj--;
        }
    }
}
void unguarded_insert_sort(int* arr, int left, int right) {
    int tmp = left;
    for(int i = left + 1; i < right; i++) {
        if(arr[tmp] > arr[i])
            tmp = i;
    }
    while(tmp > left) {
        swap(arr[tmp], arr[tmp - 1]);
        tmp--;
    }
    for(int i = left + 1; i < right; i++) {
        int numj = i;
        while(arr[numj] < arr[numj - 1]) {
            swap(arr[numj], arr[numj - 1]);
            numj--;
        }
    }
}
int main() {
    init_rand();
    int* arr = get_rand_data(SMALL_DATA_N);
    TEST(insert_sort, arr, SMALL_DATA_N);
    TEST(unguarded_insert_sort, arr, SMALL_DATA_N);
    delete[] arr;
    return 0;
}
