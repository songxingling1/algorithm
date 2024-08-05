#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    if(n % 4 != 0) {
        printf("365\n");
    } else if(n % 4 == 0 && n % 100 != 0) {
        printf("366\n");
    } else if(n % 100 == 0 && n % 400 != 0) {
        printf("365\n");
    } else if(n % 400 == 0) {
        printf("366\n");
    }
    return 0;
}