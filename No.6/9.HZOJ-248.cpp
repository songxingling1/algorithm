#include <bits/stdc++.h>
#define MAX_N 500000
using namespace std;
int arr[MAX_N + 5];
int tmp[MAX_N + 5];
long long total;
void mergeSort(int l,int r) {
    if(r - l <= 1) return;
    int mid = (l + r) / 2;
    mergeSort(l,mid);
    mergeSort(mid,r);
    int p1 = l,p2 = mid,p = l;
    while(p1 < mid || p2 < r) {
        if(p2 == r || (p1 != mid && arr[p1] <= arr[p2])) {
            tmp[p++] = arr[p1++];
        } else {
            total += mid - p1;
            tmp[p++] = arr[p2++];
        }
    }
    for(int i = l;i < r;i++) {
        arr[i] = tmp[i];
    }
}
int main() {
    int size;
    while(scanf("%d",&size) != EOF) {
        if(size == 0) break;
        total = 0;
        for(int i = 1;i <= size;i++) scanf("%d",&arr[i]);
        mergeSort(1,size + 1);
        printf("%lld\n",total);
    }
    return 0;
}