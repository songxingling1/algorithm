#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
class BigInt : public vector<int> {
private:
    void solve() {
        for(int i = 0;i < size();i++) {
            if(at(i) < 10) continue;
            if(i == size() - 1) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        while(size() > 1 && back() == 0) pop_back();
    }
public:
    BigInt() {
        push_back(0);
    }
    BigInt(int x) {
        push_back(x);
        solve();
    }
    BigInt operator+(const BigInt &i) {
        BigInt ret;
        if(size() > i.size()) {
            ret = *this;
            for(int k = 0;k < i.size();k++) {
                ret.at(k) += i.at(k);
            }
        } else {
            ret = i;
            for(int k = 0;k < size();k++) {
                ret.at(k) += at(k);
            }
        }
        ret.solve();
        return ret;
    }
    bool operator!=(const BigInt &x) {
        if(size() != x.size()) return true;
        for(int i = 0;i < size();i++) {
            if(at(i) != x[i]) return true;
        }
        return false;
    }
};
ostream &operator<<(ostream &out,const BigInt &i) {
    for(int k = i.size() - 1;k >= 0;k--) {
        printf("%d",i[k]);
    }
    return out;
}
typedef BigInt ll;
ll arr[MAX_N + 5] = {0};
ll f(int n) {
    if(n <= 2) return n;
    if(arr[n] != 0) return arr[n];
    return arr[n] = f(n - 1) + f(n - 2);
}
int main() {
    int n;
    scanf("%d",&n);
    cout << f(n) << endl;
    return 0;
}