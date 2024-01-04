#include <bits/stdc++.h>
#define MAX_S 1000
char s[MAX_S + 5];
bool isDelete[MAX_S + 5] = {false};
using namespace std;
struct node {
    bool is;
    int num;
    char op;
};
int judge(char c) {
    if(c >= '0' && c <= '9') return 0;
    if(c == '(' || c == ')') return -1;
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    return 1;
}
int judge_c(int pos) {
    if(isDelete[pos]) return 1;
    char c = s[pos];
    if(c >= '0' && c <= '9') return 0;
    if(c == ')') return -1;
    if(c == '(') return -2;
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    return 1;
}
pair<int,int> getNum(int pos) {
    int i = pos;
    int ans = 0,t;
    if(s[i] == '-') i++;
    while(judge(s[i]) == 0) {
        t = s[i] - '0';
        ans = ans * 10 + t;
        i++;
    }
    if(s[pos] == '-') ans *= -1;
    return make_pair(ans,i);
}
int qpow(int a,int b) {
    int ans = 1;
    while(b) {
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
int clac(vector<node> num) {
    vector<int> temp;
    int t = num[0].num;
    for(int i = 0;i < num.size();i++) {
        if(!num[i].is) {
            temp.push_back(num[i].num);
            continue;
        }
        switch(num[i].op) {
            case '^':
                t = qpow(temp[temp.size() - 2],temp[temp.size() - 1]);break;
            case '*':
                t = temp[temp.size() - 2] * temp[temp.size() - 1];break;
            case '/':
                t = temp[temp.size() - 2] / temp[temp.size() - 1];break;
            case '+':
                t = temp[temp.size() - 2] + temp[temp.size() - 1];break;
            case '-':
                t = temp[temp.size() - 2] - temp[temp.size() - 1];break;
        }
        temp.pop_back();
        temp.pop_back();
        temp.push_back(t);
    }
    return t;
}
int solve() {
    int size = strlen(s);
    int i = 1;
    node fd;
    vector<node> num;
    pair<int,int> getN;
    stack<char> op;
    op.push('\0');
    while(i < size) {
        if(isDelete[i]) {i++;continue;}
        if(s[i] >= '0' && s[i] <= '9') {
            getN = getNum(i);
            fd.is = false;
            fd.num = getN.first;
            num.push_back(fd);
            i = getN.second;
            continue;
        }else if (s[i] == '-' && (isDelete[i - 1] || judge(s[i - 1]) != 0) && judge_c(i - 1) != -1) {
            getN = getNum(i);
            fd.is = false;
            fd.num = getN.first;
            num.push_back(fd);
            i = getN.second;
            continue;
        } else if(s[i] == '(') {
            op.push(s[i]);
            i++;
            continue;
        } else if(s[i] == ')') {
            while(op.top() != '(' && op.size() > 1) {
                fd.is = true;
                fd.op = op.top();
                num.push_back(fd);
                op.pop();
            }
            op.pop();
            i++;
            continue;
        }else if(judge(s[i]) == 3) {
            while(op.size() > 1 && judge(op.top()) == 3) {
                fd.is = true;
                fd.op = op.top();
                op.pop();
                num.push_back(fd);
            }
            op.push(s[i]);
            i++;
            continue;
        }else if(judge(s[i]) == 2) {
            while(op.size() > 1 && judge(op.top()) >= 2) {
                fd.is = true;
                fd.op = op.top();
                op.pop();
                num.push_back(fd);
            }
            op.push(s[i]);
            i++;
            continue;
        }else if(judge(s[i]) == 1) {
            while(op.size() > 1 && judge(op.top()) >= 1) {
                fd.is = true;
                fd.op = op.top();
                op.pop();
                num.push_back(fd);
            }
            op.push(s[i]);
            i++;
            continue;
        }
    }
    while(op.size() > 1) {
        fd.is = true;
        fd.op = op.top();
        op.pop();
        num.push_back(fd);
    }
    return clac(num);
}
void removeExcessParentheses() {
    vector<int> sta;
    int size = strlen(s);
    for(int i = 1;i < size;i++) {
        if(s[i] != '(' && s[i] != ')') continue;
        if(s[i] == '(') {
            sta.push_back(i);
        } else if(s[i] == ')') {
            if(sta.empty()) isDelete[i] = true;
            else sta.pop_back();
        }
    }
    for(int i:sta) {
        isDelete[i] = true;
    }
}
int main()
{
    s[0] = '0';
    isDelete[0] = true;
    scanf("%s",s + 1);
    removeExcessParentheses();
    cout << solve() << endl;
    return 0;
}
