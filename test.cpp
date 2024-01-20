#include <bits/stdc++.h>
#define MAX_N 10000
using namespace std;
char s[MAX_N + 5];
int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.emplace(a.begin() + 1,2);
    for_each(a.begin(),a.end(),[](int i)->void{printf("%d",i);});
    return 0;
}
