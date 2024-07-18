#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    int n;
    scanf("%d", &n);
    cin >> s;
    if (s.size() != n) {
        printf("error!\n");
        return 0;
    }
    int pos = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'r') pos++;
    }
    printf("%d\n", pos);
    return 0;
}