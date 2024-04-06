#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
struct dat {
    int a,b;
} arr[MAX_N + 5];
int n;
class BigInt : public vector<int> {
public:
    void does() {
        for(int i = 0;i < size();i++) {
            if(at(i) < 10) continue;
            if(i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        while(size() > 1 && back() == 0) pop_back();
    }
    BigInt(int x) {
        push_back(x);
        does();
    }
    BigInt():vector<int>() {}
    BigInt operator/(int x) {
        BigInt ret = *this;
        int tmp = 0;
        for(int i = size() - 1;i >= 0;i--) {
            tmp = tmp * 10 + at(i);
            ret[i] = tmp / x;
            tmp %= x;
        }
        ret.does();
        return ret;
    }
    bool operator>(const BigInt &x) {
        int len1 = size(),len2 = x.size();
        if(len1 != len2) return len1 > len2;
        for(int i = len2 - 1;i >= 0;i--) {
            if(at(i) != x.at(i)) return at(i) > x.at(i);
        }
        return false;
    }
    BigInt &operator*=(int x) {
        int len = size();
        for(int i = 0;i < len;i++) at(i) *= x;
        does();
        return *this;
    }
};
ostream &operator<<(ostream &out,const BigInt &x) {
    for(int i = x.size() - 1;i >= 0;i--) printf("%d",x[i]);
    return out;
}
int main() {
    scanf("%d",&n);
    for(int i = 0;i <= n;i++) scanf("%d%d",&arr[i].a,&arr[i].b);
    sort(arr + 1,arr + 1 + n,[](const dat &i,const dat &j)->bool{
        return j.a * j.b > i.a * i.b;
    });
    BigInt temp,num = arr[0].a,ans = 0;
    for(int i = 1;i <= n;i++) {
        temp = num / arr[i].b;
        if(temp > ans) ans = temp;
        num *= arr[i].a;
    }
    cout << ans << endl;
    return 0;
}