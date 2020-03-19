#include <iostream>
using namespace std;

template <class T> class Stack{
    private: 
        int end, sz;
        T *ara;
    public:
        Stack() {
            end = 0;
        }
        Stack(int x) {
            end = 0;
            ara = new T[x];
            sz = x;
        }
        void push(T x);
        void pop();
        int size();
        int peek();
        bool is_full();
        bool is_empty();
        void clr();
        void setstacksize(int x);
};

int main() 
{
    /*
    declaration syntax :
    Stack < data_type > variable_name (size);
    or, 
    Stack < data_type > variable_name; 
    then declare the size using -> variable_name.createsize(size);
    */

    Stack <int> var(5);

    // push and pop             // current state of the stack
    var.push(5);                // 5
    var.pop();                  //
    var.push(1);                // 1
    var.push(2);                // 1 2
    var.push(3);                // 1 2 3
    var.pop();                  // 1 2 

    // top element 
    int x = var.peek(); // returns rand() if stack is empty  
    cout << x << endl;             
    

    // current stack size
     x  = var.size();
    cout << x << endl;
    return 0;
}

template<class T> bool Stack<T>::is_full() {
    return end == sz ? true : false; 
}

template<class T> bool Stack<T>::is_empty() {
    return end == 0 ? true : false;
}

template <class T> void Stack<T>::push(T x) {
    if(is_full()) {
        cout << "overflow_error" << endl; // overflow
        return;
    } 
    ara[end++] = x;
    return;
}

template <class T> void Stack<T>::pop() {
    if(is_empty()) {
        cout << "underflow_error" <<endl; // underflow
        return;
    } 
    ara[end--] = 0;
    return;
}

template<class T> int Stack<T>::size() {
    return end - 0;
}

template<class T> int Stack<T>::peek() {
    if(end == 0) return rand();
    else return ara[end-1];
}

template<class T> void Stack<T>::clr() {
    free(ara);
}

template<class T> void Stack<T>::setstacksize(int x) {
    ara = new T[x]; 
    sz = x;
}
