#include <bits/stdc++.h>
#define F(n) ((n) / 2)
#define LS(n) ((n) * 2)
#define RS(n) ((n) * 2 + 1)
using namespace std;
int *getRandData(int size) {
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100000;
    }
    return arr;
}
void normal_heap_build(int *data,int n) {
    for(int i = 2;i <= n;i++) {
        while(i > 1 && data[i] > data[F(i)]) {
            swap(data[i],data[F(i)]);
            i = F(i);
        }
    }
}
void linear_heap_build(int *data,int n) {
    for(int i = n / 2;i >= 1;i--) {
        while (LS(i) <= n) {
            int ind = i;
            if(data[LS(i)] > data[ind]) ind = LS(i);
            if(RS(i) <= n && data[RS(i)] > data[ind]) ind = RS(i);
            if(ind == i) break;
            swap(data[ind],data[i]);
            i = ind;
        }
    }
}
void heap_sort(int *data,int n) {
    int t = 1;
    for(int i = n;i >= 2;i--) {
        swap(data[1],data[i]);
        t = 1;
        while (LS(t) <= i - 1) {
            int ind = t;
            if(data[LS(t)] > data[ind]) ind = LS(t);
            if(RS(t) <= i - 1 && data[RS(t)] > data[ind]) ind = RS(t);
            if(ind == t) break;
            swap(data[ind],data[t]);
            t = ind;
        }
    }
}
void normal_heap(int *arr,int n) {
    int *data = arr - 1;
    normal_heap_build(data,n);
    heap_sort(data,n);
}
void linear_heap(int *arr,int n) {
    int *data = arr - 1;
    linear_heap_build(data,n);
    heap_sort(data,n);
}
bool check(int *arr,int n) {
    for(int i = 1;i < n;i++) {
        if(arr[i] < arr[i - 1]) return false;
    }
    return true;
}
void TEST(pair<void (*)(int*,int),char*> pkg,int *arr,int size) {
    printf("TEST : %s\t",pkg.second);
    int *temp = new int[size];
    memcpy(temp,arr,sizeof(int) * size);
    long long b = clock();
    (pkg.first)(temp,size);
    long long e = clock();
    if(check(temp,size)) {
        printf("OK\t");
    } else {
        printf("FAIL\t");
    }
    printf("%f ms\n",1000.0 * (e - b) / CLOCKS_PER_SEC);
    delete[] temp;
}
int main() {
    srand(time(0));
    int *arr = getRandData(10000000);
    TEST(pair<void (*)(int*,int),char*>(normal_heap,(char*)"normal_heap"),arr,1000);
    TEST(pair<void (*)(int*,int),char*>(linear_heap,(char*)"linear_heap"),arr,1000);
    return 0;
}