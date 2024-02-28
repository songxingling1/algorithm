#include <bits/stdc++.h>
#include <ctime>
#include <tools.hpp>
using namespace std;
int main () {
    long long begin = clock ();
    for (long long i = 0; i < 1000000000000000; i++) {
        printf ("%lld\n", i);
    }
    long long end = clock ();
    cout << (end - begin) / CLOCKS_PER_SEC << endl;
    return 0;
}
