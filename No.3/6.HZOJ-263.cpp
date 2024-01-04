#include <bits/stdc++.h>
using namespace std;
bool isValid(int a[],int n) {
    stack<int> s;
    int x = 1;
    for(int i = 0;i < n;i++) {
        if(s.empty() || s.top() < a[i]) {
            while(x <= a[i]) s.push(x),x++;
        }
        if(s.empty() || s.top() != a[i]) return false;
        s.pop();
    }
    return true;
}
int main() {
    int n,a[25],cnt = 20;
    scanf("%d",&n);
    for(int i = 0;i < n;i++) a[i] = i + 1;
    do
    {
        if(isValid(a,n)) {
            for(int i = 0;i < n;i++) {
                printf("%d",a[i]);
            }
            puts("");
            cnt--;
        }
    } while (next_permutation(a,a + n) && cnt);
    return 0;
}