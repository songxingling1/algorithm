#include <bits/stdc++.h>
using namespace std;
class A{
public:
    int j;
    static A NIL;
    A() 
};
A A::NIL;
__attribute__((constructor))
void init_nil() {
    A::NIL.j = 5;
}
int main() {
    ;
    return 0;
}
