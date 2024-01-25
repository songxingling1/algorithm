#include <iostream>
#include <cstdio>
#include <set>
#define MAX_N 100000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll gArr[MAX_N + 5] = { 0 }, gLeft[MAX_N + 5] = { 0 }, gRight[MAX_N + 5] = { 0 }, gIsDelete[MAX_N + 5] = { 0 };
multiset<pll> gHeap;
void del(ll pos) {
    gRight[gLeft[pos]] = gRight[pos];
    gLeft[gRight[pos]] = gLeft[pos];
    gIsDelete[pos] = 1;
}
int main() {
    int numM, numN, pos = 1;
    scanf("%d%d", &numN, &numM);
    scanf("%lld", gArr + 1);
    for(int i = 2, buffer; i <= numN; i++) {
        scanf("%d", &buffer);
        if(1LL * gArr[pos] * buffer < 0)
            gArr[++pos] = buffer;
        else
            gArr[pos] += buffer;
    }
    numN = pos;
    ll cnt = 0, numS = 0;
    for(int i = 1; i <= numN; i++) {
        gLeft[i] = i - 1;
        gRight[i] = i + 1;
        gHeap.emplace(abs(gArr[i]), i);
        if(gArr[i] > 0) {
            cnt++;
            numS += gArr[i];
        }
    }
    while(cnt > numM) {
        while(gIsDelete[gHeap.begin()->second])
            gHeap.erase(gHeap.begin());
        ll index = gHeap.begin()->second;
        gHeap.erase(gHeap.begin());
        if((gLeft[index] > 0 && gRight[index] <= numN) || gArr[index] > 0) {
            numS -= abs(gArr[index]);
            cnt--;
            gArr[index] += gArr[gLeft[index]] + gArr[gRight[index]];
            gHeap.emplace(abs(gArr[index]), index);
            del(gLeft[index]);
            del(gRight[index]);
        }
    }
    printf("%lld\n", numS);
    return 0;
}