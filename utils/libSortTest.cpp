#include "libSortTest.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>
bool check(const int* arr, int left, int right) {
    for(int i = left + 1; i < right; i++) {
        if(arr[i] < arr[i - 1])
            return false;
    }
    return true;
}
void init_rand() {
    printf("init rand\n");
    srand(time(0));
}
int* get_rand_data(int n) {
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 10000;
    return arr;
}