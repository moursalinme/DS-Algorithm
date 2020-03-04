// Array implementation of stack
#include <iostream>
using namespace std;

// initializing max size of the stack as 50
// you can initialize it as you want
#define SIZE 50

struct stack { 
    int array[SIZE];
    int top = -1;
};

void push(stack &s, int element);
void pop(stack &s);
void top_element(stack &s);
void isempty(stack &s);
void is_full(stack &s);

int main() 
{
    // declare a stack
    stack s;

    // push element
    push(s, 5);
    push(s, 6);

    // pop element
    pop(s);

    // print top element
    top_element(s);

    // check if stack is empty
    isempty(s);

    // check if stack is full
    is_full(s);

    return 0;
} 

void push(stack &s, int element) {
    if(s.top == SIZE -1) {
        cout << "Stack is full. Can not push element" << endl; // overflow
    } else {
        s.array[++s.top] = element;
    }
}

void pop(stack &s) {
    if(s.top==-1) {
        cout << "Stack is empty. Can not pop" <<endl; // Underflow
    } else {
        // you can initialize the top element before decrement the size
        --s.top; // s.array[s.top] = 0; s.top--;
    }
}

void top_element(stack &s) {
    if(s.top == -1) {
        cout << "Stack has no element" << endl;
    } else {
        cout << s.array[s.top] << endl;
    }
}

void isempty(stack &s) {
    if(s.top == -1) {
        cout << "Stack is empty" <<endl;
    } else {
        cout << "Stack is not empty" << endl;
    }
}

void is_full(stack &s) {
    if(s.top == SIZE-1) {
        cout << "Stack is full" << endl;
    } else {
        cout << "Stack is not full" << endl;
    }
}
