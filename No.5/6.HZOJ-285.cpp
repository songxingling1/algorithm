#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> PII;
int gUid = 0;
set<PII> gSet;
int main() {
    int length, width, buffer = 0;
    scanf("%d%d", &length, &width);
    gSet.emplace(0, gUid++);
    for(int i = 1; i <= length; i++) {
        vector<int> temp;
        temp.reserve(gSet.size());
        for(auto num : gSet) {
            temp.emplace_back(num.first);
        }
        gSet.clear();
        for(int j = 0; j < width; j++) {
            scanf("%d", &buffer);
            for(auto tmp : temp) {
                if(gSet.size() < width || gSet.begin()->first < tmp - buffer) {
                    gSet.emplace(make_pair(tmp - buffer, gUid++));
                }
                if(gSet.size() > width)
                    gSet.erase(gSet.begin());
            }
        }
    }
    auto iter = gSet.rbegin();
    printf("%d", iter->first * -1);
    iter++;
    for(; iter != gSet.rend(); iter++) {
        printf(" %d", iter->first * -1);
    }
    puts("");
    return 0;
}