#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
int n;
bool cmp(string a, string b) {
    return a + b > b + a;
}
int main() {
    scanf("%d", &n);
    vector<string> nums;
    string tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    sort(nums.begin(), nums.end(), cmp);
    for (string i : nums) {
        cout << i;
    }
    puts("");
    return 0;
}