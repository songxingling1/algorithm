// scope: 100

#include <bits/stdc++.h>
#include <vector>
#define MAX_N 1000
using namespace std;
int gA[MAX_N + 5];
int gB[MAX_N + 5];
int gInd[MAX_N + 5];
class BigNum {
protected:
    vector<int> mNum;

public:
    BigNum () : mNum (1, 0){};
    BigNum (int x) {
        if (x == 0) {
            mNum.resize (1, 0);
            return;
        }
        while (x) {
            mNum.push_back (x % 10);
            x /= 10;
        }
    }
    BigNum (const BigNum& n) = default;
    BigNum& operator= (const BigNum& n) = default;
    BigNum& operator*= (const int& n) {
        for (int& i : mNum) {
            i *= n;
        }
        for (int i = 0; i < mNum.size (); i++) {
            if (i == mNum.size () - 1
                && mNum[i] >= 10) {
                mNum.push_back (0);
                mNum[i + 1] += mNum[i] / 10;
                mNum[i] %= 10;
                continue;
            }
            mNum[i + 1] += mNum[i] / 10;
            mNum[i] %= 10;
        }
        while (mNum.size () > 1 && mNum.back () == 0)
            mNum.pop_back ();
        return *this;
    }
    bool operator> (const BigNum& x) {
        if (mNum.size () != x.mNum.size ())
            return mNum.size () > x.mNum.size ();
        int size = mNum.size ();
        for (int i = size - 1; i >= 0; --i) {
            if (mNum[i] == x.mNum[i])
                continue;
            return mNum[i] > x.mNum[i];
        }
        return false;
    }
    BigNum operator/ (const int& x) {
        BigNum ans;
        ans.mNum.pop_back ();
        int temp = 0;
        int i = mNum.size () - 1;
        for (; i >= 0; i--) {
            temp = temp * 10 + mNum[i];
            if (x > temp && ans.mNum.empty ())
                continue;
            ans.mNum.insert (ans.mNum.begin (),
                             temp / x);
            temp %= x;
        }
        return ans;
    }
    void print () {
        for (auto i = mNum.rbegin ();
             i != mNum.rend (); i++) {
            printf ("%d", *i);
        }
        puts ("");
    }
};
int main () {
    int n;
    scanf ("%d", &n);
    for (int i = 1; i <= n + 1; i++) {
        scanf ("%d%d", &gA[i], &gB[i]);
        gInd[i] = i;
    }
    sort (gInd + 2, gInd + 2 + n,
          [&] (int i, int j) -> bool {
              return gA[i] * gB[i] < gA[j] * gB[j];
          });
    BigNum che = gA[1], ans = 0, temp;
    for (int i = 2; i <= n + 1; i++) {
        temp = che / gB[gInd[i]];
        if (temp > ans)
            ans = temp;
        che *= gA[gInd[i]];
    }
    ans.print ();
    return 0;
}