#include <iostream>
using namespace std;

template <class T> class Queue {
private:
    int sz, front, back, cnt = 0;
    T *ara;
public:
    Queue() {
        front = 0; back = -1;
    }
    Queue(int x) {
        front = 0; back = -1;
        ara = new T[x];
        sz = x;
    }
    void setsize(int x){
        front = 0; back = -1;
        ara = new T[x];
        sz = x;
    }
    void enqueue(T x);
    void dequeue();
    T peek();
    bool is_full();
    bool is_empty();
    void clearqueue();
};

int main() 
{
    /*
        declaration syntax : 
        Queue < data_type > variable_name(Queue_size);
        or, 
        Queue < data_type > variable_name;
        then set the size using -> variable_name.setsize(size);
    */

    Queue <int> q(5);
    
    // enqueue                  //         state of the queue after enqueue operation
    q.enqueue(1);               //     1
    q.enqueue(2);               //     1 2
    q.enqueue(3);               //     1 2 3
    q.enqueue(4);               //     1 2 3 4
    q.enqueue(5);               //     1 2 3 4 5
    q.enqueue(6);               //     1 2 3 4 5 // enqueue overflow

    // dequeue                  //         state of the queue after dequeue operation
    q.dequeue();                //     2 3 4 5 
    q.dequeue();                //     3 4 5
    q.dequeue();                //     4 5
    
    // peek the front element
    int x = q.peek();
    cout << x << endl;

    //clear the queue;
    q.clearqueue();
}
 
template <class T> bool Queue<T>::is_empty() {
    return (cnt == 0) ? true : false; 
}

template <class T> bool Queue<T>::is_full() {
    if((front == 0 && back == sz-1) || ((front == back+1) && back!=-1)) return true;
    return false;
}

template <class T> void Queue<T>::enqueue(T x) {
    if(is_full()) {
        cout << "overflow" <<endl;
        return ;
    } 
    ++cnt;
    back = (back+1) %sz;
    ara[back] = x;
    return;
}

template <class T> void Queue<T>::dequeue() {
    if(is_empty()) {
        cout << "underflow" << endl;
        front = 0, back = -1;
        return ;
    } 
    front = (front +1) %sz;
    --cnt;
    return;
}

template <class T> T Queue<T>::peek() {
    if(is_empty()) return rand();
    else return ara[front];
}

template <class T> void Queue<T>::clearqueue() {
    front = 0; back = -1;
    free(ara);
    return;
}
