#include <bits/stdc++.h>
#include <tools.hpp>
using namespace std;
enum TEST { E1, E2, E3 };
TEST operator++ (TEST& t, int) {          // NOLINT
    int n = t;
    n++;
    TEST old = t;
    t = ( TEST )n;
    return old;
}
TEST& operator+= (TEST& n1, TEST& n2) {
    int i1 = n1, i2 = n2;
    n1 = ( TEST )(i1 + i2);
    return n1;
}
int main () {
    TEST t = E1, t2 = E2;
    t += t2;
    cout << t << endl;
    return 0;
}