#include <bits/stdc++.h>
using namespace std;
class BigInt : public vector<int> {
private:
    void proccese_digit() {
        for(size_t i = 0;i < size();i++) {
            if(at(i) < 100000) continue;
            if(i == size() - 1) push_back(0);
            at(i + 1) += at(i) / 100000;
            at(i) %= 100000;
        }
        while(size() > 1 && back() == 0) pop_back();
    }
public:
    BigInt() {
        push_back(0);
    }
    BigInt(int x) {
        push_back(x);
        proccese_digit();
    }
    BigInt &operator+=(const BigInt &x) {
        for(size_t i = 0;i < x.size();i++) {
            if(i >= size()) {
                push_back(x[i]);
                continue;
            }
            at(i) += x[i];
        }
        proccese_digit();
        return *this;
    }
};
ostream &operator<<(ostream &out,const BigInt &x) {
    printf("%d",x[x.size() - 1]);
    for(int i = x.size() - 2;i >= 0;i--) {
        for(int j = 10000;j > 0;j /= 10) {
            printf("%d",x[i] % (j * 10) / j);
        }
    }
    return out;
}
typedef BigInt ll;
ll f[2][15][15];
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= k;i++) {
        f[1][i][i] = 1;
    }
    for(int i = 2;i <= n;i++) {
        for(int j = 1;j <= k;j++) {
            for(int l = 1;l <= k;l++) {
                f[i % 2][j][l] = 0;
                for(int g = 1;g <= k;g++) {
                    if(g == l) continue;
                    f[i % 2][j][l] += f[(i - 1) % 2][j][g];
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 1;i <= k;i++) {
        for(int j = 1;j <= k;j++) {
            if(i == j) continue;
            ans += f[n % 2][i][j];
        }
    }
    cout << ans << endl;
    return 0;
}