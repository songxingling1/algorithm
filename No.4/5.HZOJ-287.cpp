#include <bits/stdc++.h>
using namespace std;
int main() {
    priority_queue<int,vector<int>,greater<int>> food;
    int n,t;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d",&t);
        food.emplace(t);
    }
    int ans = 0,i1,i2;
    while (food.size() != 1)
    {

        i1 = food.top();
        food.pop();
        i2 = food.top();
        food.pop();
        ans += i1 + i2;
        food.emplace(i1 + i2);
    }
    printf("%d\n",ans);
    return 0;
}