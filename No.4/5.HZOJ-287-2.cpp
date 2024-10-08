/*#include <bits/stdc++.h>
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
}*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    set<pair<int, int>> food;
    int n, t;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        food.emplace(t, i);
    }
    int ans = 0, i1, i2, i = 1;
    while (food.size() != 1) {
        i1 = food.begin()->first;
        food.erase(food.begin());
        i2 = food.begin()->first;
        food.erase(food.begin());
        ans += i1 + i2;
        i++;
        food.emplace(i1 + i2, n + i);
    }
    printf("%d\n", ans);
    return 0;
}