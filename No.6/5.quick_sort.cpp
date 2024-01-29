#include <cstdio>
#include <iostream>
#include "libSortTest.h"
using namespace std;
void quick_sort(int* arr, int left, int right) {
    if(right - left <= 2) {
        if(right - left <= 1)
            return;
        if(arr[left] > arr[left + 1])
            swap(arr[left], arr[left + 1]);
        return;
    }
    int pos1 = left, pos2 = right - 1, key = arr[left];
    while(pos1 < pos2) {
        while(pos1 < pos2 && key <= arr[pos2])
            --pos2;
        if(pos1 < pos2) {
            arr[pos1++] = arr[pos2];
        }
        while(pos1 < pos2 && arr[pos1] <= key)
            ++pos1;
        if(pos1 < pos2) {
            arr[pos2--] = arr[pos1];
        }
    }
    arr[pos1] = key;
    quick_sort(arr, left, pos1);
    quick_sort(arr, pos1 + 1, right);
}
void quick_sort_v1(int* arr, int left, int right) {
    if(right - left <= 2) {
        if(right - left <= 1)
            return;
        if(arr[left] > arr[left + 1])
            swap(arr[left], arr[left + 1]);
        return;
    }
    int pos1 = left, pos2 = right - 1, key = arr[left];
    do {
        while(arr[pos1] < key)
            pos1++;
        while(arr[pos2] > key)
            pos2--;
        if(pos1 <= pos2) {
            swap(arr[pos1], arr[pos2]);
            pos1++;
            pos2--;
        }
    } while(pos1 <= pos2);
    quick_sort_v1(arr, left, pos1);
    quick_sort_v1(arr, pos1, right);
}
int three_point_select(int numa, int numb, int numc) {
    if(numa > numb)
        swap(numa, numb);
    if(numa > numc)
        swap(numa, numc);
    if(numb > numc)
        swap(numb, numc);
    return numb;
}
void quick_sort_v2(int* arr, int left, int right) {
    if(right - left <= 2) {
        if(right - left <= 1)
            return;
        if(arr[left] > arr[left + 1])
            swap(arr[left], arr[left + 1]);
        return;
    }
    int pos1 = left, pos2 = right - 1,
        key = three_point_select(arr[left], arr[right] - 1,
                                 arr[(left + right) / 2]);
    do {
        while(arr[pos1] < key)
            pos1++;
        while(arr[pos2] > key)
            pos2--;
        if(pos1 <= pos2) {
            swap(arr[pos1], arr[pos2]);
            pos1++;
            pos2--;
        }
    } while(pos1 <= pos2);
    quick_sort_v2(arr, left, pos1);
    quick_sort_v2(arr, pos1, right);
}
void quick_sort_v3(int* arr, int left, int right) {
    while(left < right) {
        if(right - left <= 2) {
            if(right - left <= 1)
                return;
            if(arr[left] > arr[left + 1])
                swap(arr[left], arr[left + 1]);
            return;
        }
        int pos1 = left, pos2 = right - 1,
            key = three_point_select(arr[left], arr[right] - 1,
                                     arr[(left + right) / 2]);
        do {
            while(arr[pos1] < key)
                pos1++;
            while(arr[pos2] > key)
                pos2--;
            if(pos1 <= pos2) {
                swap(arr[pos1], arr[pos2]);
                pos1++;
                pos2--;
            }
        } while(pos1 <= pos2);
        quick_sort_v3(arr, left, pos1);          // left
        left = pos1;
    }
}
#define THRESHOLD 16
void quick_sort_v4_kids(int* arr, int left, int right) {
    while(right - left > THRESHOLD) {
        int pos1 = left, pos2 = right - 1,
            key = three_point_select(arr[left], arr[right] - 1,
                                     arr[(left + right) / 2]);
        do {
            while(arr[pos1] < key)
                pos1++;
            while(arr[pos2] > key)
                pos2--;
            if(pos1 <= pos2) {
                swap(arr[pos1], arr[pos2]);
                pos1++;
                pos2--;
            }
        } while(pos1 <= pos2);
        quick_sort_v4_kids(arr, left, pos1);          // left
        left = pos1;
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
void quick_sort_v4(int* arr, int left, int right) {
    quick_sort_v4_kids(arr, left, right);
    unguarded_insert_sort(arr, left, right);
}
int main() {
    init_rand();
    int* arrS = get_rand_data(SMALL_DATA_N);
    int* arrB = get_rand_data(BIG_DATA_N);
    TEST(quick_sort, arrS, SMALL_DATA_N);
    TEST(quick_sort, arrB, BIG_DATA_N);
    TEST(quick_sort_v1, arrB, BIG_DATA_N);
    TEST(quick_sort_v2, arrB, BIG_DATA_N);
    TEST(quick_sort_v3, arrB, BIG_DATA_N);
    TEST(quick_sort_v4, arrB, BIG_DATA_N);
    delete[] arrS;
    delete[] arrB;
    return 0;
}