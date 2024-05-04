#include <bits/stdc++.h>
#define MAX_N 200
using namespace std;
class BigInt : public vector<int> {
public:
    BigInt(int x) {
        push_back(x);
        proccess_digit();
    }
    BigInt() {
        push_back(0);
    }
    BigInt &operator*=(int x) {
        for(int i = 0;i < size();i++) at(i) *= x;
        proccess_digit();
        return *this;
    }
    BigInt operator*(int x) {
        BigInt ret = *this;
        ret *= x;
        return ret;
    }
    BigInt operator+(int x) {
        BigInt ret = *this;
        ret[0] += x;
        ret.proccess_digit();
        return ret;
    }
private:
    void proccess_digit() {
        for(int i = 0;i < size();i++) {
            if(at(i) < 10) continue;
            if(i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        while(size() > 1 && back() == 0) pop_back();
    }
};
ostream  &operator<<(ostream &out,const BigInt &x) {
    for(int i = x.size() - 1;i >= 0;i--) {
        out << x[i];
    }
    return out;
}
BigInt f[MAX_N + 5] = {0};
int main() {
    int n;
    scanf("%d",&n);
    f[1] = 2;
    for(int i = 2;i <= n;i++) {
        f[i] = f[i - 1] * 2 + 2;
    }
    cout << f[n] << endl;
    return 0;
}