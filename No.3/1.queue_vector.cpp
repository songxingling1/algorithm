#include <bits/stdc++.h>
using namespace std;
template<class T> class Vector {
public:
    T *data;
    int size, count;

public:
    Vector()
    : data(nullptr)
    , size(0)
    , count(0) {}
    Vector(T n)
    : data(new T[n])
    , size(n)
    , count(0) {}
    ~Vector() {
        if (data != nullptr) delete[] data;
    }
    int insert(int pos, T val) {
        if (pos >= size || pos < 0) return -1;
        data[pos] = val;
        return 0;
    }
    T at(int pos) {
        if (pos >= size || pos < 0) return -1;
        return data[pos];
    }
};
template<class T> class Queue {
public:
    Vector<T> *data;
    int size, count, head, tail;

public:
    Queue(int n)
    : data(new(nothrow) Vector<T>(n))
    , size(n)
    , head(0)
    , tail(0)
    , count(0) {}
    ~Queue() {
        if (data != nullptr) delete data;
    }
    int push(T);
    int pop();
    T front();
    bool empty();
};
template<class T> int Queue<T>::push(T val) {
    if (size == count) return -1;
    if (data->insert(tail, val) == -1) return -1;
    tail++;
    if (tail == size) tail = 0;
    count++;
    return 0;
}
template<class T> int Queue<T>::pop() {
    if (empty()) return -1;
    head++;
    if (head == size) head = 0;
    count--;
    return 0;
}
template<class T> T Queue<T>::front() {
    if (count == 0) return -1;
    return data->at(head);
}
template<class T> bool Queue<T>::empty() {
    return count == 0;
}
template<class T> void output_Queue(Queue<T> *p) {
    printf("Queue :");
    for (int i = 0; i < p->count; i++) {
        printf("%4d", p->data->at((p->head + i) % p->size));
    }
    puts("\n\n");
}
int main() {
    srand(time(0));
#define MAX_OP 10
    Queue<int> *q = new Queue<int>(5);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 5,
            val = rand() % 100;  // 0,1 : pop | 2,3,4 : push
        switch (op) {
            case 0:
            case 1:
                printf("front of queue : %d\n", q->front());
                q->pop();
                break;
            case 2:
            case 3:
            case 4:
                printf("push %d to queue\n", val);
                q->push(val);
                break;
        }
        output_Queue(q);
    }
    delete q;
    return 0;
}
