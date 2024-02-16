#include <bits/stdc++.h>
using namespace std;
int f (int n) {          // NOLINT
    if (n == 1)
        return 1;
    return n * f (n - 1);
}
struct Dat {
    int mN;
    int mCode, mRet, *mPreRet;
    Dat (int n, int* preRet)
        : mN (n), mCode (0), mRet (0), mPreRet (preRet) {}
};

int nonF (int n) {
    stack<Dat> s;
    int ans;
    s.emplace (n, &ans);
    while (!s.empty ()) {
        Dat& cur = s.top ();
        switch (cur.mCode) {
            case 0:
                if (cur.mN == 1) {
                    *(cur.mPreRet) = 1;
                    s.pop ();
                } else {
                    cur.mCode = 1;
                }
                break;
            case 1:
                cur.mCode = 2;
                s.emplace (cur.mN - 1, &(cur.mRet));
                break;
            case 2:
                *(cur.mPreRet) = cur.mN * cur.mRet;
                s.pop ();
                break;
        }
    }
    return ans;
}
int main () {
    int n;
    while (scanf ("%d", &n) != EOF) {
        printf ("%d\n%d\n", f (n), nonF (n));
    }
    return 0;
}