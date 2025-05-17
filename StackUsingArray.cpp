
#include <iostream>
#include <string>
using namespace std;

template<class t>
class Stack {
private:
    int top = -1;
    t arr[100];

public:
    Stack();
    Stack(t value);
    void push(t value);
    t pop();
    t get_top();
    bool is_empty();
    void print();
};

template<class t>
Stack<t>::Stack() {
    top++;
}

template<class t>
Stack<t>::Stack(t value) {
    top++;
    arr[top] = value;
}

template<class t>
void Stack<t>::push(t value) {
    if (top < 99) {  // index 0 to 99 = 100 elements
        top++;
        arr[top] = value;
    } else {
        cout << "Stack is full." << endl;
    }
}

template<class t>
t Stack<t>::pop() {
    t num = arr[top];
    if (!is_empty()) {
        top--;
    }
    return num;
}

template<class t>
t Stack<t>::get_top() {
    if (!is_empty()) {
        return arr[top];
    } else {
        cout << "Stack is empty" << endl;
        return t(); 
    }
}

template<class t>
bool Stack<t>::is_empty() {
    return top < 0;
}

template<class t>
void Stack<t>::print() {
    if (!is_empty()) {
        cout << "[ ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i];
            if (i != 0) cout << " , ";
        }
        cout << " ]" << endl;
    } else {
        cout << "Stack is empty" << endl;
    }
}

int main() {
    Stack<string> s("Ahmed");
    s.push("Mostafa");
    s.push("Mona");
    s.push("Mohammed");
    s.pop();
    s.print();
    cout << s.get_top() << endl;

    return 0;
}
