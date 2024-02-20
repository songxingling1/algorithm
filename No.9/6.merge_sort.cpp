#include <cstdio>
#include <iostream>
#include <queue>
#include "libSortTest.hpp"

int* gBuff;
void mergeSort (int* arr, int left, int right) {          // NOLINT
    if (right - left <= 1)
        return;
    int mid = (left + right) / 2;
    mergeSort (arr, left, mid);
    mergeSort (arr, mid, right);
    int pos1 = left, pos2 = mid, pos = 0;
    while (pos1 < mid || pos2 < right) {
        if (pos2 == right || (pos1 < mid && arr[pos1] <= arr[pos2])) {
            gBuff[pos++] = arr[pos1++];
        } else {
            gBuff[pos++] = arr[pos2++];
        }
    }
    for (int i = left; i < right; i++)
        arr[i] = gBuff[i - left];
}
struct Dat {
    Dat (int l, int r) : mL (l), mR (r) {}
    int mL, mR;
};
void mergeSortOnce (int* arr, int left, int right) {
    int mid = (left + right) / 2;
    int pos1 = left, pos2 = mid, pos = left;
    while (pos1 < mid || pos2 < right) {
        if (pos2 == right || (pos1 < mid && arr[pos1] <= arr[pos2])) {
            gBuff[pos++] = arr[pos1++];
        } else {
            gBuff[pos++] = arr[pos2++];
        }
    }
    for (int i = left; i < right; i++)
        arr[i] = gBuff[i];
}
void nonMergeSort (int* arr, int left, int right) {
    vector<Dat> tmp;
    tmp.emplace_back (left, right);
    for (int i = 0; i < tmp.size (); i++) {
        Dat top = tmp[i];
        int mid = (top.mR + top.mL) / 2;
        if (mid - top.mL >= 2) {
            tmp.emplace_back (top.mL, mid);
        }
        if (top.mR - mid >= 2) {
            tmp.emplace_back (mid, top.mR);
        }
    }
    for (int i = tmp.size () - 1; i >= 0; i--) {          // NOLINT
        mergeSortOnce (arr, tmp[i].mL, tmp[i].mR);
    }
}
using namespace std;
int main () {
    init_rand ();
    int* arrS = get_rand_data (SMALL_DATA_N);
    int* arrB = get_rand_data (BIG_DATA_N);
    gBuff = new int[BIG_DATA_N];
    TEST (mergeSort, arrS, SMALL_DATA_N);
    TEST (mergeSort, arrB, BIG_DATA_N);
    TEST (nonMergeSort, arrB, BIG_DATA_N);
    delete[] arrS;
    delete[] arrB;
    delete[] gBuff;
    return 0;
}