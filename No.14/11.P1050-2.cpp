#include <bits/stdc++.h>
using namespace std;
class BigInt : public vector<int> {
public:
    BigInt(const char *s,int k) {
        int len = strlen(s);
        for(int i = 0,j = len - 1;i < k;i++,j--) {
            push_back(s[j] - '0');
        }
    }
    BigInt() {
        push_back(0);
    }
    BigInt(int n,int v):vector<int>(n,v) {}
    BigInt(int x) {
        push_back(x);
        proccess_digit();
    }
    BigInt operator*(const BigInt &x) {
        BigInt ret(min(MaxLen,static_cast<int>(size() + x.size() - 1)),0);
        for(int i = 0;i < size();i++) {
            for(int j = 0;j < x.size();j++) {
                if(i + j >= MaxLen) continue;
                ret[i + j] += at(i) * x[j];
            }
        }
        ret.proccess_digit();
        return ret;
    }
    BigInt &operator*=(int x) {
        for(int i = 0;i < size();i++) at(i) *= x;
        proccess_digit();
        return *this;
    }
    static int MaxLen;
private:
    void proccess_digit() {
        for(int i = 0;i < size();i++) {
            if(at(i) < 10) continue;
            if(i + 1 < MaxLen) {
                if(i + 1 == size()) push_back(0);
                at(i + 1) += at(i) / 10;
            }
            at(i) %= 10;
        }
    }
};
int BigInt::MaxLen = 0;
ostream &operator<<(ostream &out,const BigInt &x) {
    for(int i = x.size() - 1;i >= 0;i--) {
        out << x[i];
    }
    return out;
}
int main() {
    char *s = new char[110];
    int k;
    scanf("%s%d",s,&k);
    BigInt::MaxLen = k;
    BigInt n(s,k);
    BigInt pre_y = n,y;
    vector<int> arr;
    for(int i = 0;i < n.size();i++) {
        y = pre_y;
        int cnt = 1;
        while((y * n).at(i) != n[i]) {
            y = y * pre_y;
            cnt++;
            if(cnt == 11) break;
        }
        if(cnt == 11) {
            printf("-1\n");
            return 0;
        }
        arr.push_back(cnt);
        pre_y = y;
    }
    BigInt ans = 1;
    for(int i = 0;i < arr.size();i++) {
        ans *= arr[i];
    }
    cout << ans << endl;
    return 0;
}