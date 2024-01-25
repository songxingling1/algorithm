#include <bits/stdc++.h>
using namespace std;
set<int> gSet;
set<int>& get_set() {
    return gSet;
}
int main() {
    gSet.emplace(1);
    gSet.emplace(2);
    get_set().clear();
    cout << get_set().size() << " " << gSet.size() << endl;
    return 0;
}