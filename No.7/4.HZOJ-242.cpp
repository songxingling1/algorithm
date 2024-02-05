#include <bits/stdc++.h>
#include <climits>
using namespace std;
/*
解题方案：
进行二分查找，边界条件为 tail - head > 0.001，
判断函数为先获取数据的前缀和，整个前缀和数组减去
A，之后在原数组找到最大的区间和（用前缀和优化），
如果大于0，返回true，否则返回false；

不开double见祖宗！！！
*/
vector<double> gData;
vector<double> gSum;
int gN, gM;
bool check (double a) {
    gSum[0] = 0;
    for (int i = 1; i <= gN; i++)
        gSum[i] = gData[i] + gSum[i - 1] - a;
    double minNum = 0;
    for (int i = gM; i <= gN; i++) {
        minNum = min (minNum, gSum[i - gM]);
        if (gSum[i] - minNum > 0)
            return true;
    }
    return false;
}
double solve () {
    double head = 0, tail = gSum[gN], mid;
    while (tail - head > 0.001) {
        mid = (head + tail) / 2;
        if (check (mid))
            head = mid;
        else
            tail = mid;
    }
    return tail;
}
int main () {
    scanf ("%d%d", &gN, &gM);
    gData.resize (gN + 5, 0);
    gSum.resize (gN + 5, 0);
    for (int i = 1; i <= gN; i++) {
        scanf ("%lf", &gData[i]);
        gSum[i] = gData[i] + gSum[i - 1];
    }
    int ans = ( int )(solve () * 1000);
    printf ("%d\n", ans);
    return 0;
}