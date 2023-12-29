#include <bits/stdc++.h>
using namespace std;
int n;
stack<int> sta;
vector<int> ans;
stack<string> a;
void makeAnswer() {
    string as;
    for(int i = 0;i < ans.size();i++) {
        as += to_string(ans[i]);
    }
    a.push(as);
}
void solve(int step,int top) {
    if(step > 2 * n) {
        makeAnswer();
        return;
    }
    if(top > n) {
        int temp = sta.top();
        ans.push_back(temp);
        sta.pop();
        solve(step + 1,top);
        sta.push(temp);
        ans.pop_back();
        return;
    }
    sta.push(top);
    solve(step + 1,top + 1);
    sta.pop();
    if(!sta.empty()) {
        int temp = sta.top();
        ans.push_back(temp);
        sta.pop();
        solve(step + 1,top);
        sta.push(temp);
        ans.pop_back();
    }
}
int main() {
    scanf("%d",&n);
    solve(1,1);
    int i = 0;
    while((!a.empty()) && i < 20) {
        printf("%s\n",(a.top()).c_str());
        a.pop();
        i++;
    }
    return 0;
}