#include <bits/stdc++.h>
using namespace std;
char h[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int main() {
    int n;
    scanf("%d", &n);
    string s;
    if (n == 0) s = "0";
    while (n) {
        s = h[n % 16] + s;
        n /= 16;
    }
    cout << s << endl;
    return 0;
}