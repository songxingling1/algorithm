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
ll f[MAX_N + 5] = {};
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    f[1] = k;
    f[2] = k * (k - 1);
    f[3] = k * (k - 1) * (k - 2);
    for(int i = 4;i <= n;i++) {
        f[i] = f[i - 1] * (k - 2);
        f[i] += f[i - 2] * (k - 1);
    }
    cout << f[n] << endl;
    return 0;
}