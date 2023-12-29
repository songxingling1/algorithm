#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    vector<string> ops(n,"");
    vector<string> f;
    for(int i = 0;i < n;i++) {
        cin >> ops[i];
    }
    string w;
    cin >> w;
    bool flag = false;
    for(int i = 0;i < n;i++) {
        if(ops[i] == w) {
            f.push_back(ops[i]);
            flag = true;
            break;
        }
        if(ops[i] == "return") f.pop_back();
        else f.push_back(ops[i]);
    }
    if(flag) {
        for(int i = 0;i < f.size();i++) {
            if(i) printf("->");
            printf("%s",(f[i]).c_str());
        }
        printf("\n");
    } else {
        printf("NOT REFERENCED");
    }
    return 0;
}
