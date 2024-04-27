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
};
ostream &operator<<(ostream &out,const BigInt &i) {
    for(int k = i.size() - 1;k >= 0;k--) {
        printf("%d",i[k]);
    }
    return out;
}
typedef BigInt ll;
ll f[MAX_N + 5] = {0};
int main() {
    int n;
    scanf("%d",&n);
    f[1] = 1;
    f[2] = 2;
    for(int i = 3;i <= n;i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n] << endl;
    return 0;
}