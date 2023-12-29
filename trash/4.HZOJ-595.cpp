#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> functions;
string want;
string makeAnswer(stack<string> s) {
    string a = want;
    string t;
    while(!s.empty()) {
        t = s.top();
        s.pop();
        a = t + "->" + a;
    }
    return a;
}
void solve() {
    bool flag = false;
    vector<string> f;
    string s;
    for(int i = 0;i < functions.size();i++) { //遍历函数调用
        s = functions[i];
        if(s == want) {f.push_back(s);flag = true;break;}
        if(s == "return") f.pop_back();
        else f.push_back(s);
    }
    if(flag) {
        for(int i = 0;i < f.size();i++) {
            if(i != 0) printf("->");
            printf("%s",(f[i]).c_str());
        }
        printf("\n");
        return;
    }
    printf("NOT REFERENCED\n");
}
int main() {
    scanf("%d",&n);
    functions.resize(n);
    for(int i = 0;i < n;i++) {
        cin >> functions[i];
    }
    cin >> want;
    solve();
    return 0;
}
