#include <algorithm>
#include <bits/stdc++.h>
#define MAX_N 20
using namespace std;
int n;
int arr[MAX_N + 5];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }
    int cnt = 0, maxx = 1, flag, ind;
    stack<int> st;
    do {
        flag = 0;
        while (!st.empty()) st.pop();
        ind = 1;
        maxx = 1;
        st.push(0);
        while (ind <= n) {
            if (st.top() < arr[ind]) {
                if (maxx > n) break;
                st.push(maxx);
                maxx++;
            } else if (st.top() == arr[ind]) {
                st.pop();
                ind++;
                if (ind == n + 1) flag = 1;
            } else {
                break;
            }
        }
        if (flag) {
            for (int i = 1; i <= n; i++) {
                printf("%d", arr[i]);
            }
            puts("");
            cnt++;
        }
    } while (next_permutation(arr + 1, arr + 1 + n) &&
             cnt < 20);
    return 0;
}