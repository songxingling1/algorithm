/*************************************************************************
    > File Name: solve.cpp
    > Author:
    > Mail:
    > Created Time:
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

int min_num(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    return a;
}

int max_num(int a,int b,int c) {
    if(a < b) swap(a,b);
    if(a < c) swap(a,c);
    return a;
}

inline int clac(int a,int b,int c) {
    return abs(a - b) + abs(b - c) + abs(c - a);
}

int func(queue<int> que1, queue<int> que2, queue<int> que3) {
    int a,b,c,ans = 0x3f3f3f3f,tmp1,tmp2;
    while(que1.size() >= 1 && que2.size() >= 1 && que3.size() >= 1) {
        a = que1.front();
        b = que2.front();
        c = que3.front();
        tmp1 = min_num(a,b,c);
        tmp2 = max_num(a,b,c);
        ans = min(ans,abs((tmp2 - tmp1) * 2));
        if(a == b || b == c || a == c) break;
        if(tmp1 == a) que1.pop();
        else if(tmp1 == b) que2.pop();
        else que3.pop();
    }
    return ans;
}

int main() {
    int m, n, k, x;
    queue<int> que1, que2, que3;
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++) {
        cin >> x;
        que1.push(x);
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        que2.push(x);
    }
    for (int i = 0; i < k; i++) {
        cin >> x;
        que3.push(x);
    }
    cout << func(que1, que2, que3) << endl;
    return 0;
}
