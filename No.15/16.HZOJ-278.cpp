#include <bits/stdc++.h>
#define MAX_L 1000000
using namespace std;
char s[MAX_L + 5];
int ind[MAX_L + 5];
void getNext(int n) {
    ind[1] = 0;
    for(int i = 2;i <= n;i++) {
        int j = ind[i - 1];
        while(1) {
            if(s[j + 1] == s[i]) {
                ind[i] = j + 1;
                break;
            }
            if(j == 0) {
                ind[i] = 0;
                break;
            }
            j = ind[j];
        }
    }
}
int main() {
    int l;
    scanf("%d",&l);
    scanf("%s",s + 1);
    getNext(l);
    for(int i = 2;i <= l;i++) {
        if(i % (i - ind[i]) == 0 && i / (i - ind[i]) >= 2) {
            printf("%d %d\n",i,i / (i - ind[i]));
        }
    }
    return 0;
}