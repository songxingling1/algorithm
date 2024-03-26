#include <bits/stdc++.h>
#define MAX_N 30000
using namespace std;
deque<int> q;
int main() {
    int weight, n;
    scanf("%d%d", &weight, &n);
    for (int i = 1, tmp; i <= n; i++) {
        scanf("%d", &tmp);
        q.push_back(tmp);
    }
    sort(q.begin(), q.end());
    int count = 0, l, r;
    while (!q.empty()) {
        count++;
        if (n == 1) {
            break;
        }
        l = q.front(), r = q.back();
        if (l + r <= weight) {
            q.pop_front();
            q.pop_back();
            n -= 2;
        } else {
            q.pop_back();
            n--;
        }
    }
    printf("%d\n", count);
    return 0;
}