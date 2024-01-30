#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<long long> gData;
vector<long long> gTemp;
long long gAns;
void merge_sort (long long left, long long right) {
    if (right - left <= 1)
        return;
    long long mid = (left + right) / 2;
    merge_sort (left, mid);
    merge_sort (mid, right);
    long long p1 = left, p2 = mid, pos = left;
    while (p1 < mid || p2 < right) {
        if (p1 == mid
            || (p2 < right && gData[p1] > gData[p2])) {
            gAns += mid - p1;
            gTemp[pos++] = gData[p2++];
        } else {
            gTemp[pos++] = gData[p1++];
        }
    }
    for (long long i = left; i < right; i++) {
        gData[i] = gTemp[i];
    }
}
int main () {
    long long size;
    while (scanf ("%lld", &size)) {
        if (size == 0)
            break;
        gData.clear ();
        gData.resize (size);
        gTemp.clear ();
        gTemp.resize (size);
        for (long long i = 0; i < size; i++) {
            scanf ("%lld", &gData[i]);
        }
        gAns = 0;
        merge_sort (0, size);
        printf ("%lld\n", gAns);
    }
    return 0;
}