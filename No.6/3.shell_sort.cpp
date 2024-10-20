#include <iostream>
#include <cstdio>
#include <ctime>
#include "libSortTest.hpp"
using namespace std;
void insert_sort(int* arr, int left, int right, int step) {
    int tmp = left;
    for (int i = left + step; i < right; i += step) {
        if (arr[tmp] > arr[i]) tmp = i;
    }
    while (tmp > left) {
        swap(arr[tmp], arr[tmp - step]);
        tmp -= step;
    }
    for (int i = left + 2 * step; i < right; i += step) {
        int numj = i;
        while (arr[numj] < arr[numj - step]) {
            swap(arr[numj], arr[numj - step]);
            numj--;
        }
    }
}
void shell_sort(int* arr, int left, int right) {
    int numk = 2, numn = (right - left),
        step = numn / numk == 0 ? 1 : numn / numk;
    do {
        step = numn / numk == 0 ? 1 : numn / numk;
        for (int i = left; i < left + step; i++) {
            insert_sort(arr, i, right, step);
        }
        numk *= 2;
    } while (step != 1);
}
void shell_sort_hibbard(int* arr, int left, int right) {
    int step = 1, numn = right - left;
    while (step <= numn / 2) step = step * 2 + 1;
    do {
        step /= 2;
        for (int i = left; i < left + step; i++) {
            insert_sort(arr, i, right, step);
        }
    } while (step > 1);
}
int main() {
    int* arr = get_rand_data(BIG_DATA_N);
    init_rand();
    TEST(shell_sort, arr, BIG_DATA_N);
    TEST(shell_sort_hibbard, arr, BIG_DATA_N);
    return 0;
}