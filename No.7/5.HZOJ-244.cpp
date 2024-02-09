#include <bits/stdc++.h>
#define MAX_N 500
using namespace std;
struct point {
    int mX, mY;
} gArr[MAX_N + 5];
int gTmp[MAX_N + 5];
bool check_kid (int n, int c, int left, int right, int len) {
    for (int i = left; i <= right; i++) {
        gTmp[i] = gArr[i].mY;
    }
    sort (gTmp + left, gTmp + right + 1);
    for (int i = left + c - 1; i <= right; i++) {
        if (gTmp[i] - gTmp[i - c + 1] < len)
            return true;
    }
    return false;
}
bool check (int len, int n, int c) {
    int j = 1;
    for (int i = 1; i <= n; i++) {
        while (gArr[i].mX - gArr[j].mX >= len)
            j++;
        if (i - j + 1 < c)
            continue;
        if (check_kid (n, c, j, i, len))
            return true;
    }
    return false;
}
int solve (int left, int right, int n, int c) {
    int mid = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (check (mid, n, c))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}
int main () {
    int c, n;
    scanf ("%d%d", &c, &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d", &gArr[i].mX, &gArr[i].mY);
    }
    sort (gArr + 1, gArr + 1 + n,
          [] (const point& i, const point& j) -> bool {
              if (i.mX != j.mX)
                  return i.mX < j.mX;
              return i.mY < j.mY;
          });
    printf ("%d\n", solve (0, 10000, n, c));
    return 0;
}