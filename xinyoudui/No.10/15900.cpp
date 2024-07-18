#include <bits/stdc++.h>
using namespace std;
struct ctz {
    string name;
    string id;
    int age, sex, neng;
    int cnt;
};
vector<ctz> ch, ol, p;
int main() {
    int n;
    ctz t;
    scanf("%d", &n);
    for (int i = 1, temp; i <= n; i++) {
        cin >> t.name >> t.id;
        temp = 2000 - stoi(t.id.substr(6, 4));
        t.age = temp;
        t.sex = (t.id[16] - '0') % 2;
        t.neng = stoi(t.id.substr(18));
        t.cnt = i;
        if (temp < 100) {
            ch.push_back(t);
        } else if (temp > 1000) {
            ol.push_back(t);
        } else {
            p.push_back(t);
        }
    }
    sort(ch.begin(), ch.end(), [](const ctz &i, const ctz &j) -> bool {
        if (i.age != j.age) return i.age < j.age;
        return i.cnt < j.cnt;
    });
    sort(ol.begin(), ol.end(), [](const ctz &i, const ctz &j) -> bool {
        if (i.age != j.age) return i.age > j.age;
        return i.cnt < j.cnt;
    });
    sort(p.begin(), p.end(), [](const ctz &i, const ctz &j) -> bool {
        if (i.sex != j.sex) {
            return i.sex < j.sex;
        }
        if (i.sex == 0) {
            if (i.age != j.age) return i.age < j.age;
            else return i.cnt < j.cnt;
        }
        if (i.neng != j.neng) {
            return i.neng < j.neng;
        }
        return i.cnt < j.cnt;
    });
    for (ctz i : ch) {
        cout << i.name << endl;
    }
    for (ctz i : ol) {
        cout << i.name << endl;
    }
    for (ctz i : p) {
        cout << i.name << endl;
    }
    return 0;
}