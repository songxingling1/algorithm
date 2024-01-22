#include <bits/stdc++.h>
#include <ctime>
#include <functional>
using namespace std;
void test1() {
    cout << "set base usage" << endl;
    set<int> s;
    cout << s.size() << endl;
    s.insert(3);          // 3
    cout << s.size() << endl;
    s.insert(4);          // 3, 4
    cout << s.size() << endl;
    s.insert(2);          // 3, 4, 2
    cout << s.size() << endl;
}
void test2() {
    cout << "set item unique feature:  " << endl;
    set<int> s;
    cout << s.size() << endl;
    s.insert(3);
    cout << s.size() << endl;
    s.insert(4);
    cout << "insert 4 : " << s.size() << endl;
    s.insert(4);
    cout << "insert 4 : " << s.size() << endl;
}
void test3() {
    cout << "set item unique feature 2 :  " << endl;
    typedef pair<int, int> PII;
    set<PII> s;
    int tot = 0;
    cout << s.size() << endl;
    s.insert(PII(3, tot));
    tot++;
    cout << s.size() << endl;
    s.insert(PII(4, tot));
    tot++;
    cout << "insert 4 : " << s.size() << endl;
    s.insert(PII(4, tot));
    cout << "insert 4 : " << s.size() << endl;
}
void test4() {
    cout << "foreach set item : " << endl;
    typedef pair<int, int> PII;
    set<PII> s;
    int tot = 0;
    s.insert(PII(4, tot++));
    s.insert(PII(3, tot++));
    s.insert(PII(4, tot++));
    for(auto x : s) {
        cout << "(" << x.first << " " << x.second << ")" << endl;
    }
}
void test5() {
    cout << "ser replace heap : " << endl;
    typedef pair<int, int> PII;
    set<PII> s;
    for(int i = 0; i < 10; i++) {
        s.insert(PII(rand() % 20 * -1, i));          // push
    }
    for(int i = 0; i < 4; i++) {
        cout << "s.begin() = " << s.begin()->first * -1 << endl;          // top
        s.erase(s.begin());          // pop
        cout << "pop heap" << endl;
    }
}
int main() {
    srand(time(0));
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}