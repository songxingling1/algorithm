#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <ostream>
#include <vector>
#include "libSortTest.h"
using namespace std;
struct data {
    int mNum1, mNum2;
};
ostream& operator<<(ostream& out, data num) {
    printf("(%d,%d)", num.mNum1, num.mNum2);
    return out;
}
template <int size = 10, typename T>
void output(T begin, T end, const char* str = "arr") {
    printf("%s[%d] = ", str, size);
    for_each(begin, end,
             [](__typeof(*begin) num) -> void { cout << num << " "; });
    puts("");
}
void test1() {
    // sort array
    printf("-----------------------testing "
           "test1()-------------------------\n");
    int* arr = get_rand_data(10);
    output(arr, arr + 10);
    sort(arr, arr + 10);          //[arr,arr+10)
    output(arr, arr + 10);
    sort(arr, arr + 10, greater<int>());
    output(arr, arr + 10);
    delete[] arr;
}
void test2() {
    // sort vector
    printf("-----------------------testing "
           "test2()-------------------------\n");
    vector<int> arr;
    arr.reserve(10);
    for(int i = 0; i < 10; i++)
        arr.push_back(rand() % 100000);
    output(arr.begin(), arr.end());
    sort(arr.begin(), arr.end());
    output(arr.begin(), arr.end());
    sort(arr.begin(), arr.end(), greater<int>());
    output(arr.begin(), arr.end());
}
void test3() {
    printf("-----------------------testing "
           "test3()-------------------------\n");
    vector<data> arr;
    arr.reserve(10);
    data temp{};
    for(int i = 0; i < 10; i++) {
        temp.mNum1 = rand() % 10;
        temp.mNum2 = rand() % 10;
        arr.push_back(temp);
    }
    output(arr.begin(), arr.end());
    sort(arr.begin(), arr.end(),
         [](const data& num1, const data& num2) -> bool {
             if(num1.mNum1 != num2.mNum1)
                 return num1.mNum1 < num2.mNum1;
             return num1.mNum2 > num2.mNum2;
         });
    output(arr.begin(), arr.end());
}
void test4() {
    printf("-----------------------testing "
           "test4()-------------------------\n");
    int* arr = get_rand_data(10);
    int* ind = get_rand_data(10);
    for(int i = 0; i < 10; i++)
        ind[i] = i;
    output(arr, arr + 10);
    sort(ind, ind + 10, [=](int num1, int num2) -> bool {
        return arr[num1] < arr[num2];
    });
    output(arr, arr + 10);
    output(ind, ind + 10, "ind");
}
int main() {
    init_rand();
    test1();
    test2();
    test3();
    test4();
    return 0;
}