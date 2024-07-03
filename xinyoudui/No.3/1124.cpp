#include <cstdio>
using namespace std;
int check(int x) {
    while (x) {
        if (x % 10 == 5) return 1;
        x /= 10;
    }
    return 0;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 15; i <= n; i += 3) {
        if (check(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}