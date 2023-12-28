#include <bits/stdc++.h>
using namespace std;
struct Stack {
    int *data;
    int size,top;
};

Stack *initStack(int n) {
    Stack *s = new Stack;
    s->data = new int[n];
    s->size = n;
    s->top = -1;
    return s;
}

void clearStack(Stack *s) {
    if(s == nullptr) return;
    delete[] s->data;
    delete s;
}

bool emptyStack(Stack *s) {
    return s->top == -1;
}

int topStack(Stack *s) {
    if(emptyStack(s)) return -1;
    return s->data[s->top];
}

int pushStack(Stack *s,int val) {
    if(s->top + 1 == s->size) return -1;
    s->top += 1;
    s->data[s->top] = val;
    return 0;
}

int popStack(Stack *s) {
    if(emptyStack(s)) return -1;
    s->top -= 1;
    return 0;
}

void outputStack(Stack *s) {
    printf("Stack : ");
    for(int i = s->top;i >= 0;i--) {
        printf("%4d",s->data[i]);
    }
    printf("\n\n");
}

int main() {
    srand(time(0));
    #define MAX_OP 10
    Stack *s = initStack(5);
    for(int i = 0;i < MAX_OP;i++) {
        int op = rand() % 3,val = rand() % 100;
        switch(op) {
            case 0:
                printf("pop stack, item = %d\n",topStack(s));
                popStack(s);
                break;
            case 1:
            case 2:
                printf("push stack, item = %d\n",val);
                pushStack(s,val);
                break;
        }
        outputStack(s);
    }
    clearStack(s);
}
