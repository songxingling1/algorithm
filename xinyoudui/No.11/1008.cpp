#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
    char ch;
    int zm = 0, sz = 0, qt = 0;
    while (true) {
        ch = getchar();
        if (ch == '#') break;
        if (ch >= '0' && ch <= '9') sz++;
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) zm++;
        else qt++;
    }
    printf("zm=%d\nsz=%d\nqt=%d\n", zm, sz, qt);
    return 0;
}