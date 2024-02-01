#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include "tools.hpp"
using namespace std;
void output (int* arr, int n, int ind = -1) {
    int len = 0;
    for (int i = 0; i < n; i++)
        len += printf ("%4d", i);
    puts ("");
    for (int i = 0; i < len; i++)
        printf ("-");
    puts ("");
    for (int i = 0; i < n; i++) {
        if (ind == i) {
            printf ("\033[1;31m%4d\033[0m", arr[i]);
            continue;
        }
        printf ("%4d", arr[i]);
    }
    puts ("");
}
int binary_search (const int* arr, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) / 2;
        printf ("[%d, %d], mid = %d, arr[%d] = %d\n",
                head, tail, mid, mid, arr[mid]);
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            head = mid + 1;
        else
            tail = mid - 1;
    }
    return -1;
}
void test_binary_search (int n) {
    int* arr = new int[n];
    arr[0] = get_rand<int>(0, 10);
    for (int i = 1; i < n; i++)
        arr[i] = arr[i - 1] + get_rand<int> (0, 10);
    output (arr, n);
    int x;
    while (scanf ("%d", &x)) {
        if (x == -1)
            break;
        int ind = binary_search (arr, n, x);
        output (arr, n, ind);
    }
    delete[] arr;
}
#define EXP 1e-4
double f (double x) {
    if (x >= 0)
        x -= min (x, 3000.0) * 0.03;
    if (x > 3000)
        x -= (min (x, 12000.0) - 3000) * 0.1;
    if (x > 12000)
        x -= (min (x, 25000.0) - 12000) * 0.2;
    if (x > 25000)
        x -= (min (x, 35000.0) - 25000) * 0.25;
    if (x > 35000)
        x -= (min (x, 55000.0) - 35000) * 0.3;
    if (x > 55000)
        x -= (min (x, 80000.0) - 55000) * 0.35;
    if (x > 80000)
        x -= (x - 80000) * 0.45;
    return x;
}
double binary_algorithm (double y) {
    double head = 0, tail = 1000000, mid;
    while (tail - head >= EXP) {
        mid = (head + tail) / 2.0;
        printf ("[%f, %f], mid = %f, arr[%f] = %f\n",
                head, tail, mid, mid, f (mid));
        if (f (mid) < y)
            head = mid;
        else
            tail = mid;
    }
    return head;
}
void test_binary_algorithm () {
    double y;
    while (scanf ("%lf", &y)) {
        if (y < 0)
            break;
        double x = binary_algorithm (y);
        printf ("f(%.2f) = %.2f\n", x, y);
    }
}
int main () {
#define MAX_N 10
    test_binary_search (MAX_N);
    test_binary_algorithm ();
    return 0;
}