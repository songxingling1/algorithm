#include <bits/stdc++.h>
#define CMP(a, b) (strcmp(a, b) == 0)
using namespace std;
char p1[10], p2[10];
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s%s", p1, p2);
        if (CMP(p1, p2)) {
            printf("Tie\n");
        } else if (CMP(p1, "Rock") && CMP(p2, "Scissors")) {
            printf("Player1\n");
        } else if (CMP(p1, "Scissors") && CMP(p2, "Paper")) {
            printf("Player1\n");
        } else if (CMP(p1, "Paper") && CMP(p2, "Rock")) {
            printf("Player1\n");
        } else if (CMP(p2, "Rock") && CMP(p1, "Scissors")) {
            printf("Player2\n");
        } else if (CMP(p2, "Scissors") && CMP(p1, "Paper")) {
            printf("Player2\n");
        } else if (CMP(p2, "Paper") && CMP(p1, "Rock")) {
            printf("Player2\n");
        }
    }
    return 0;
}