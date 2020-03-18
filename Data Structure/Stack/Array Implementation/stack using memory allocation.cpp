#include <iostream>
using namespace std;

template <class T> class Stack{
    private: 
        int end, sz;
        T *ara;
    public:
        Stack(int x) {
            end = 0;
            ara = new T[x];
            sz = x;
        }
        void push(T x);
        void pop();
        int size();
        void top();
};

int main() 
{
    /* declaration syntax :
    Stack < data_type > variable_name (size); */

    Stack <int> var(5);

    // push and pop             // current state of the stack
    var.push(5);                // 5
    var.pop();                  //
    var.push(1);                // 1
    var.push(2);                // 1 2
    var.push(3);                // 1 2 3
    var.pop();                  // 1 2 

    // top element               
    var.top();

    // current stack size
    int x  = var.size();
    cout << x << endl;
    return 0;
}

template <class T> void Stack<T>::push(T x) {
    if(end == sz) {
        cout << "overflow_error" << endl; // overflow
        return;
    } 
    ara[end++] = x;
    return;
}

template <class T> void Stack<T>::pop() {
    if(end == 0) {
        cout << "underflow_error" <<endl; // underflow
        return;
    } 
    ara[end--] = 0;
    return;
}

template<class T> int Stack<T>::size() {
    return end - 0;
}

template<class T> void Stack<T>:: top() {
    if(end == 0) {
        cout << "underflow_error" <<endl;
        return;
    }
    cout << ara[end-1] << endl;
    return;
}
