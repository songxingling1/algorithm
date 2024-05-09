#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
string str[MAX_N + 5];
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        cin >> str[i];
    }
    sort(str + 1,str + 1 + n,[](const string &i,const string &j)->bool{
        return i + j > j + i;
    });
    for(int i = 1;i <= n;i++) {
        cout << str[i];
    }
    cout << endl;
    return 0;
}