#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
int n;
vector<string> nums;
bool cmp(string i, string j) {
    return i + j > j + i;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        nums.emplace_back();
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end(), cmp);
    for (string i : nums) {
        cout << i;
    }
    cout << endl;
    return 0;
}