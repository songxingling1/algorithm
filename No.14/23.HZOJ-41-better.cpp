#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
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
    BigInt &operator*=(const int x) {
        for(int i = 0;i < size();i++) at(i) *= x;
        proccese_digit();
        return *this;
    }
    BigInt operator*(const int x) {
        BigInt ret(*this);
        ret *= x;
        return ret;
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
ll f[MAX_N + 5][MAX_K + 5] = {{0}};
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    f[1][0] = 1;
    for(int i = 2;i <= n;i++) {
        for(int j = 0;j < k;j++) {
            for(int c = 0;c < k;c++) {
                if(c == j) continue;
                f[i][j] += f[i - 1][c];
            }
        }
    }
    ll sum = 0;
    for(int i = 1;i < k;i++) {
        sum += f[n][i];
    }
    cout << sum * k << endl;
    return 0;
}