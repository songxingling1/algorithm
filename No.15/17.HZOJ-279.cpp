#include <bits/stdc++.h>
#define MAX_L 1000000
using namespace std;
char a[MAX_L + 5],b[MAX_L + 5];
int getMin(const char *s) {
    int n = strlen(s),i = 0,j = 1,k = 0;
    while(k < n && i < n && j < n) {
        if(s[(i + k) % n] == s[(j + k) % n]) k++;
        else if(s[(i + k) % n] > s[(j + k) % n]) {
            i = i + k + 1;
            k = 0;
        } else {
            j = j + k + 1;
            k = 0;
        }
        if(i == j) j++;
    }
    return min(i,j);
}
int main() {
    scanf("%s%s",a,b);
    int ma = getMin(a),mb = getMin(b);
    int N = strlen(a);
    int flag = 1;
    for(int n = 0;n < N;n++) {
        if(a[(ma + n) % N] == b[(mb + n) % N]) continue;
        flag = 0;
        break;
    }
    if(flag) {
        printf("Yes\n");
        for(int n = 0;n < N;n++) {
            printf("%c",a[(ma + n) % N]);
        }
        puts("");
    } else {
        printf("No\n");
    }
    return 0;
}