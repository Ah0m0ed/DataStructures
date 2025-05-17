#include <iostream>
using namespace std;

template <class t>
class Stack {
private:
    struct Node {
        t value;
        Node* next;
    };
    Node* top;

public:
    Stack() { top = nullptr; }

    void push(t val);
    void pop(t& variable);
    void pop();
    t get_top();
    bool is_empty();
    void display();
};

template<class t>
bool Stack<t>::is_empty() {
    return top == nullptr;
}

template<class t>
void Stack<t>::push(t val) {
    Node* temp = new Node;
    temp->value = val;
    temp->next = top;
    top = temp;
}

template<class t>
t Stack<t>::get_top() {
    if (!is_empty()) {
        return top->value;
    } else {
        cout << "Stack is empty";
        return t();  
    }
}

template<class t>
void Stack<t>::pop() {
    if (is_empty()) {
        cout << "Stack is empty on pop." << endl;
    } else {
        Node* temp = top;
        top = temp->next;
        delete temp;
    }
}

template<class t>
void Stack<t>::pop(t& variable) {
    if (is_empty()) {
        cout << "Stack is empty on pop." << endl;
    } else {
        variable = top->value;
        Node* temp = top;
        top = temp->next;
        delete temp;
    }
}

template<class t>
void Stack<t>::display() {
    if (is_empty()) {
        cout << "Stack Is Empty." << endl;
    } else {
        Node* temp = top;
        cout << "[ ";
        while (temp != nullptr) {
            cout << temp->value;
            if (temp->next != nullptr) cout << " , ";
            temp = temp->next;
        }
        cout << " ]" << endl;
    }
}

int main() {
    Stack<int> s;
    s.push(100);
    s.push(200);
    s.push(40);
    s.push(20);
    s.display();
    return 0;
}
