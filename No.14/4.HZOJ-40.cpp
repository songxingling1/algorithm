#include <bits/stdc++.h>
#define MAX_N 500
using namespace std;
class BigInt : public vector<int> {
private:
    void precces_digit() {
        for(size_t i = 0;i < size();i++) {
            if(at(i) < 10) continue;
            if(i == size() - 1) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        while(size() > 1 && back() == 0) pop_back();
    }
public:
    BigInt(int x) {
        push_back(x);
        precces_digit();
    }
    BigInt() {
        push_back(0);
    }
    BigInt &operator+=(const BigInt &x) {
        for(size_t i = 0;i < x.size();i++) {
            if(i >= size()) {
                push_back(x[i]);
                continue;
            }
            at(i) += x[i];
        }
        precces_digit();
        return *this;
    }
    BigInt operator+(const BigInt &x) {
        BigInt ret = *this;
        ret += x;
        return ret;
    }
};
ostream &operator<<(ostream &out,const BigInt &x) {
    for(int i = x.size() - 1;i >= 0;i--) {
        printf("%d",x[i]);
    }
    return out;
}
BigInt f[MAX_N + 5] = {0};
int main() {
    int n;
    scanf("%d",&n);
    f[1] = 0;
    f[2] = 1;
    f[3] = 1;
    for(int i = 4;i <= n;i++) {
        f[i] = f[i - 2] + f[i - 3];
    }
    cout << f[n] << endl;
    return 0;
}