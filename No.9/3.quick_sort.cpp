#include <cstdio>
#include <iostream>
#include <stack>
#include "libSortTest.hpp"
using namespace std;
void quickSort (int* arr, int left, int right) {          // NOLINT
    if (right - left <= 2) {
        if (right - left <= 1)
            return;
        if (arr[left] > arr[left + 1])
            swap (arr[left], arr[left + 1]);
        return;
    }
    int pos1 = left, pos2 = right - 1, key = arr[left];
    while (pos1 < pos2) {
        while (pos1 < pos2 && key <= arr[pos2])
            --pos2;
        if (pos1 < pos2) {
            arr[pos1++] = arr[pos2];
        }
        while (pos1 < pos2 && arr[pos1] <= key)
            ++pos1;
        if (pos1 < pos2) {
            arr[pos2--] = arr[pos1];
        }
    }
    arr[pos1] = key;
    quickSort (arr, left, pos1);
    quickSort (arr, pos1 + 1, right);
}
void quickSortV1 (int* arr, int left,          // NOLINT
                  int right) {
    if (right - left <= 2) {
        if (right - left <= 1)
            return;
        if (arr[left] > arr[left + 1])
            swap (arr[left], arr[left + 1]);
        return;
    }
    int pos1 = left, pos2 = right - 1, key = arr[left];
    do {
        while (arr[pos1] < key)
            pos1++;
        while (arr[pos2] > key)
            pos2--;
        if (pos1 <= pos2) {
            swap (arr[pos1], arr[pos2]);
            pos1++;
            pos2--;
        }
    } while (pos1 <= pos2);
    quickSortV1 (arr, left, pos1);
    quickSortV1 (arr, pos1, right);
}
int threePointSelect (int numa, int numb, int numc) {
    if (numa > numb)
        swap (numa, numb);
    if (numa > numc)
        swap (numa, numc);
    if (numb > numc)
        swap (numb, numc);
    return numb;
}
void quickSortV2 (int* arr, int left, int right) {          // NOLINT
    if (right - left <= 2) {
        if (right - left <= 1)
            return;
        if (arr[left] > arr[left + 1])
            swap (arr[left], arr[left + 1]);
        return;
    }
    int pos1 = left, pos2 = right - 1,
        key = threePointSelect (arr[left], arr[right] - 1,
                                arr[(left + right) / 2]);
    do {
        while (arr[pos1] < key)
            pos1++;
        while (arr[pos2] > key)
            pos2--;
        if (pos1 <= pos2) {
            swap (arr[pos1], arr[pos2]);
            pos1++;
            pos2--;
        }
    } while (pos1 <= pos2);
    quickSortV2 (arr, left, pos1);
    quickSortV2 (arr, pos1, right);
}
void quickSortV3 (int* arr, int left, int right) {          // NOLINT
    while (left < right) {
        if (right - left <= 2) {
            if (right - left <= 1)
                return;
            if (arr[left] > arr[left + 1])
                swap (arr[left], arr[left + 1]);
            return;
        }
        int pos1 = left, pos2 = right - 1,
            key = threePointSelect (arr[left], arr[right] - 1,
                                    arr[(left + right) / 2]);
        do {
            while (arr[pos1] < key)
                pos1++;
            while (arr[pos2] > key)
                pos2--;
            if (pos1 <= pos2) {
                swap (arr[pos1], arr[pos2]);
                pos1++;
                pos2--;
            }
        } while (pos1 <= pos2);
        quickSortV3 (arr, left, pos1);          // left
        left = pos1;
    }
}
#define THRESHOLD 16
void quickSortV4Kids (int* arr, int left,          // NOLINT
                      int right) {
    while (right - left > THRESHOLD) {
        int pos1 = left, pos2 = right - 1,
            key = threePointSelect (arr[left], arr[right] - 1,
                                    arr[(left + right) / 2]);
        do {
            while (arr[pos1] < key)
                pos1++;
            while (arr[pos2] > key)
                pos2--;
            if (pos1 <= pos2) {
                swap (arr[pos1], arr[pos2]);
                pos1++;
                pos2--;
            }
        } while (pos1 <= pos2);
        quickSortV4Kids (arr, left, pos1);          // left
        left = pos1;
    }
}
void unguardedInsertSort (int* arr, int left,          // NOLINT
                          int right) {
    int tmp = left;
    for (int i = left + 1; i < right; i++) {
        if (arr[tmp] > arr[i])
            tmp = i;
    }
    while (tmp > left) {
        swap (arr[tmp], arr[tmp - 1]);
        tmp--;
    }
    for (int i = left + 1; i < right; i++) {
        int numj = i;
        while (arr[numj] < arr[numj - 1]) {
            swap (arr[numj], arr[numj - 1]);
            numj--;
        }
    }
}
void quickSortV4 (int* arr, int left, int right) {          // NOLINT
    quickSortV4Kids (arr, left, right);
    unguardedInsertSort (arr, left, right);
}
struct Data {
    Data (int* arr, int l, int r)
        : mArr (arr), mLeft (l), mRight (r), mX (0), mCode (0) {}
    int* mArr;
    int mLeft, mRight, mX;
    int mCode;
};
void nonQuickSort (int* arr, int l, int r) {
    stack<Data> s;
    s.emplace (arr, l, r);
    int pos1, pos2, key;
    while (!s.empty ()) {
        Data& cur = s.top ();
        switch (cur.mCode) {
            case 0:
                if (cur.mRight - cur.mLeft <= 2) {
                    if (cur.mRight - cur.mLeft <= 1)
                        s.pop ();
                    else {
                        if (cur.mArr[cur.mLeft]
                            > cur.mArr[cur.mLeft + 1])
                            swap (cur.mArr[cur.mLeft],
                                  cur.mArr[cur.mLeft + 1]);
                        s.pop ();
                    }
                } else {
                    cur.mCode = 1;
                }
                break;
            case 1:
                pos1 = cur.mLeft;
                pos2 = cur.mRight - 1;
                key = cur.mArr[cur.mLeft];
                while (pos1 < pos2) {
                    while (pos1 < pos2 && key <= cur.mArr[pos2])
                        --pos2;
                    if (pos1 < pos2) {
                        cur.mArr[pos1++] = cur.mArr[pos2];
                    }
                    while (pos1 < pos2 && cur.mArr[pos1] <= key)
                        ++pos1;
                    if (pos1 < pos2) {
                        cur.mArr[pos2--] = cur.mArr[pos1];
                    }
                }
                cur.mArr[pos1] = key;
                cur.mX = pos1;
                cur.mCode = 2;
                break;
            case 2:
                cur.mCode = 3;
                s.emplace (cur.mArr, cur.mLeft, cur.mX);
                break;
            case 3:
                cur.mCode = 4;
                s.emplace (cur.mArr, cur.mX + 1, cur.mRight);
                break;
            case 4:
                s.pop ();
                break;
        }
    }
}
int main () {
    init_rand ();
    int* arrS = get_rand_data (SMALL_DATA_N);
    int* arrB = get_rand_data (BIG_DATA_N);
    TEST (quickSort, arrS, SMALL_DATA_N);
    TEST (quickSort, arrB, BIG_DATA_N);
    TEST (quickSortV1, arrB, BIG_DATA_N);
    TEST (quickSortV2, arrB, BIG_DATA_N);
    TEST (quickSortV3, arrB, BIG_DATA_N);
    TEST (quickSortV4, arrB, BIG_DATA_N);
    TEST (nonQuickSort, arrB, BIG_DATA_N);
    delete[] arrS;
    delete[] arrB;
    return 0;
}