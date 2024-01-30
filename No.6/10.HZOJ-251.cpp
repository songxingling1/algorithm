#include <bits/stdc++.h>
#include <bits/types/FILE.h>
#include <random>
#include <vector>
#define MAX_N 10000
using namespace std;
struct point {
    int mX, mY;
};
vector<point> gPoints (MAX_N + 5);
vector<point> gTemp;
int main () {
    int ans = 0;
    int n;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d", &gPoints[i].mX, &gPoints[i].mY);
    }
    gTemp.assign (gPoints.begin (), gPoints.end ());
    int left = 1, right = n;
    sort (gTemp.begin () + 1, gTemp.begin () + 1 + n,
          [] (point& i, point& j) -> bool {
              if (i.mY == j.mY)
                  return i.mX < j.mX;
              return i.mY < j.mY;
          });
    while (left < right) {
        ans += abs (gTemp[right].mY - gTemp[left].mY);
        ++left;
        --right;
    }
    sort (gPoints.begin () + 1, gPoints.begin () + 1 + n,
          [&] (point& i, point& j) -> bool {
              if (i.mX == j.mX)
                  return i.mY < j.mY;
              return i.mX < j.mX;
          });
    for (int i = 0; i < n; i++)
        gPoints[i + 1].mX -= i;
    sort (gPoints.begin () + 1,
          gPoints.begin () + 1 + n,
          [] (point& i, point& j) -> bool {
              return i.mX < j.mX;
          });
    left = 1;
    right = n;
    while (left < right) {
        ans +=
            abs (gPoints[right].mX - gPoints[left].mX);
        ++left;
        --right;
    }
    printf ("%d\n", ans);
    return 0;
}