#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
class BigInt : public vector<int> {
public:
    void d() {
        for(int i = 0;i < size();i++) {
            if(at(i) < 10) continue;
            if(i == size() - 1) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        while(size() > 1 && back() == 0) pop_back();
    }
    BigInt(int x) {
        push_back(x);
        d();
    }
    BigInt():vector<int>() {}
    bool operator>(BigInt &a) {
        int size1 = size(),size2 = a.size();
        if(size1 != size2) return size1 > size2;
        for(int i = size1 - 1;i >= 0;i--) {
            if(at(i) != a.at(i)) return at(i) > a.at(i);
        }
        return false;
    }
    BigInt operator/(int x) {
        BigInt ans(*this);
        int tmp = 0;
        for(int i = size() - 1;i >= 0;i--) {
            tmp = tmp * 10 + at(i);
            ans[i] = tmp / x;
            tmp %= x;
        }
        ans.d();
        return ans;
    }
    BigInt &operator*=(int x) {
        for(int &i:*this) {
            i *= x;
        }
        d();
        return *this;
    }
};
typedef BigInt ll;
struct da {
    int a,b;
};
da arr[MAX_N + 5];
bool cmp(da i,da j) {
    return j.a * j.b > i.a * i.b;
}
ostream &operator<<(ostream &out,const BigInt &x) {
    for(int i = x.size() - 1;i >= 0;i--) {
        printf("%d",x[i]);
    }
    return out;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0;i <= n;i++) {
        scanf("%d%d",&arr[i].a,&arr[i].b);
    }
    sort(arr + 1,arr + 1 + n,cmp);
    ll num = arr[0].a,ans = 0,temp;
    for(int i = 1;i <= n;i++) {
        temp = num / arr[i].b;
        if(temp > ans) ans = temp;
        num *= arr[i].a;
    }
    cout << ans << endl;
    return 0;
}