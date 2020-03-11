/*
    After declaring a queue, read the size and then use createq() 
    function to allocate memory for the queue. Don't forget to use eraseq()
    fucntion to free the allocated memory when you're done.
*/

#include <iostream>
using namespace std;

class Queue {
    public:
    int siz{}, front{}, rear{};
    int *p;

    void createq();
    void push(int x);
    void pop();
    void frontelement();
    void size();
    void eraseq();
    void traverse();
};

int main() 
{
    Queue q; // decare queue
    cin >> q.siz; // read the size
    q.createq(); // allocate memory

    // push some elements
    q.push(5);    
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(3);

    // check the size
    cout << "Size = " ; q.size();

    // pop elements
    q.pop();
    q.pop();
    q.pop();

    // check the font element
    q.frontelement();

    // treaverse the queue
    q.traverse();

    // free the memory
    q.eraseq();

    return 0;
}

void Queue::createq() {
    p = new int[siz];
    if(!p) cout << "Failed to allocate memory" <<endl;
}

void Queue::push(int x) {
    if(rear == siz) {
        cout << "Cannot push element into the queue" <<endl; 
    }
    else {
        p[rear++] = x; 
    }
}

void Queue::pop() {
    if(front == rear && front == siz) 
        cout << "Dont have any element" << endl;
    else {
        for(int i = front; i < rear-1; ++i) {
            p[i] = p[i+1];
        }
        rear--;
    } 
}

void Queue::frontelement() {
    if(rear != 0) cout << p[0] << endl;
    else cout << "Empty queue" << endl;
}

void Queue:: size() {
    cout << rear << endl;
}

void Queue::traverse() {
    if(rear == 0) cout << "Empty queue" << endl;
    for(int i = 0; i < rear; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;
}

void Queue::eraseq() {
    free(p);
}

