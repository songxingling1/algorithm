#include <bits/stdc++.h>
#define MAX_C 50000
using namespace std;
struct dat { // 结构体 奶牛产奶时间
    int l,r,id;
} arr[MAX_C + 5]; // 奶牛
int ans[MAX_C + 5]; // 结果
int main() {
    int c;
    scanf("%d",&c); // 输入
    for(int i = 1;i <= c;i++) {
        scanf("%d%d",&arr[i].l,&arr[i].r);
        arr[i].id = i;
    }
    sort(arr + 1,arr + 1 + c,[](const dat &i,const dat &j)->bool{
        if(i.l != j.l) return i.l < j.l;
        return i.id < j.id;
    }); // 排序
    vector<int> x; // 开始挤奶
    int flag;
    x.push_back(arr[1].r);
    ans[arr[1].id] = x.size();
    for(int i = 2;i <= c;i++) { // 遍历每一头奶牛
        flag = 0;
        for(int j = 0;j <= x.size() - 1;j++) { //查看每一个机器
            if(x[j] < arr[i].l) {
                ans[arr[i].id] = j + 1;
                x[j] = arr[i].r;
                flag = 1;
                break;
            }
        }
        if(!flag) {//如果没有空闲机器
            x.push_back(arr[i].r);
            ans[arr[i].id] = x.size();
        }
    }
    printf("%ld\n",x.size());//输出
    for(int i = 1;i <= c;i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
}