#include <bits/stdc++.h>
using namespace std;
char s[55][55];
char ww[55];
int main() {
    int h,w,si,sj;
    scanf("%d%d%d%d",&h,&w,&si,&sj);
    for(int i = 1;i <= h;i++) {
        scanf("%s",s[i] + 1);
    }
    scanf("%s",ww + 1);
    for(int i = 1;ww[i] != '\0';i++) {
        int nx,ny;
        switch(ww[i]) {
            case 'L':
                nx = si;
                ny = sj - 1;
                if(nx > 0 && ny > 0 && nx <= h && ny <= w && s[nx][ny] != '#') {
                    si = nx;
                    sj = ny;
                }
                break;
            case 'R':
                nx = si;
                ny = sj + 1;
                if(nx > 0 && ny > 0 && nx <= h && ny <= w && s[nx][ny] != '#') {
                    si = nx;
                    sj = ny;
                }
                break;
            case 'U':
                nx = si - 1;
                ny = sj;
                if(nx > 0 && ny > 0 && nx <= h && ny <= w && s[nx][ny] != '#') {
                    si = nx;
                    sj = ny;
                }
                break;
            case 'D':
                nx = si + 1;
                ny = sj;
                if(nx > 0 && ny > 0 && nx <= h && ny <= w && s[nx][ny] != '#') {
                    si = nx;
                    sj = ny;
                }
                break;
            
        }
    }
    printf("%d %d",si,sj);
    return 0;
}