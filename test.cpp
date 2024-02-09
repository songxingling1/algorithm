#include <bits/stdc++.h>
#include <cstdlib>
#include <unordered_map>
using namespace std;
int gTot = 0;
class A {
private:
    A* mD;

public:
    A () {
        gTot++;
        mD = gTot < 5 ? new A : nullptr;
    }
    ~A () {
        delete mD;
    }
};
int main () {
    A* a = new A;
    delete a;
    return 0;
}
