#include <bits/stdc++.h>
#include <queue>
#define MAX_N 10000
using namespace std;
char s[MAX_N + 5];
int main() {
    priority_queue<int> p;
    p.emplace(5);
    p.emplace(6);
    cout << p.top() << endl;
    return 0;
}