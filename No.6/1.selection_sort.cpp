#include <iostream>
#include <cstdio>
#include <ctime>
#include "libSortTest.hpp"
using namespace std;
void selection_sort(int* arr, int left, int right) {
    for(int i = left; i < right - 1; i++) {
        int ind = i;
        for(int j = i + 1; j < right; j++) {
            if(arr[j] < arr[ind])
                ind = j;
        }
        swap(arr[i], arr[ind]);
    }
}
using namespace std;
int main() {
    init_rand();
    int* arr = get_rand_data(SMALL_DATA_N);
    TEST(selection_sort, arr, SMALL_DATA_N);
    delete[] arr;
    return 0;
}