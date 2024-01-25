#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <set>
using namespace std;
struct commodity {
    int mDay, mPrice;
    commodity()
        : mDay(0), mPrice(0) {}
    commodity(int _day, int _price)
        : mDay(_day), mPrice(_price) {}
};
struct cmp {
    bool operator()(const commodity& aNum, const commodity& bNum) {
        if(aNum.mDay == bNum.mDay)
            return aNum.mPrice < bNum.mPrice;
        return aNum.mDay > bNum.mDay;
    }
};
int main() {
    priority_queue<commodity, vector<commodity>, cmp> commoditys;
    int length, price, day;
    scanf("%d", &length);
    for(int i = 1; i <= length; i++) {
        scanf("%d%d", &price, &day);
        commoditys.push(commodity(day, price));
    }
    set<pair<int, int>> answers;
    int uid = 0;
    commodity temp;
    while(!commoditys.empty()) {
        temp = commoditys.top();
        commoditys.pop();
        if(temp.mDay > answers.size()) {
            answers.emplace(temp.mPrice, uid++);
        } else {
            if(answers.begin()->first < temp.mPrice) {
                answers.erase(answers.begin());
                answers.emplace(temp.mPrice, uid);
            }
        }
    }
    int ans = 0;
    for(auto iNum : answers) {
        ans += iNum.first;
    }
    printf("%d\n", ans);
    return 0;
}