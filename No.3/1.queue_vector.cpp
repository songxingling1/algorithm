#include <bits/stdc++.h>
using namespace std;
template<class T>
class Vector {
private:
    T *data;
    int size,count;
public:
    Vector():data(nullptr),size(0),count(0) {}
    Vector(T n):data(new T[n]),size(n),count(0) {}
    ~Vector() {
        delete[] data;
    }
    int insert(int pos,T val) {
        if(pos >= size) return -1;
        data[pos] = val;
        return 0;
    }
    T at(int pos) {
        if(pos >= size) return -1;
        return data[pos];
    }
};
template<class T>
class Queue {
private:
    Vector<T> *data;
    int size,count,head,tail;
public:
    Queue(int n):data(new(nothrow) Vector<T>(n)),size(n),head(0),tail(0),count(0) {}
    ~Queue() {
        delete data;
    }
    int push(T);
    int pop();
    T front();
    bool empty();
};
template<class T>
int Queue<T>::push(T val) {
    if(size == count) return -1;
    if(data->insert(tail,val) == -1) return -1;
    tail++;
    if(tail == size) tail = 0;
    count++;
    return 0;
}
template<class T>
int Queue<T>::pop() {
    if(empty()) return -1;
    head++;
    if(head == size) head = 0;
    count--;
    return 0;
}
template<class T>
T Queue<T>::front() {
    return data->at(head);
}
template<class T>
bool Queue<T>::empty() {
    return size == 0;
}
int main() {
    return 0;
}
