#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 5;

template<class t>
class Queue {
private:
    t arr[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    Queue();
    bool is_full();
    bool is_empty();
    void enqueue(t val);
    t dequeue();
    int get_front_i();
    int get_rear_i();
    t get_front_v();
    t get_rear_v();
    int get_size();
    void clear();
    void display();
    int search(t val);
};

template<class t>
Queue<t>::Queue() {
    front = 0;
    rear = -1;
    count = 0;
}

template<class t>
bool Queue<t>::is_full() {
    return count == MAX_SIZE;
}

template<class t>
bool Queue<t>::is_empty() {
    return count == 0;
}

template<class t>
void Queue<t>::enqueue(t val) {
    if (is_full()) {
        cout << "Queue is full on enqueue !!" << endl;
    } else {
        count++;
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = val;
    }
}

template<class t>
t Queue<t>::dequeue() {
    t temp{};
    if (is_empty()) {
        cout << "Queue is empty on dequeue !!" << endl;
    } else {
        count--;
        temp = arr[front];
        front = (front + 1) % MAX_SIZE;
    }
    return temp;
}

template<class t>
int Queue<t>::get_front_i() {
    if (is_empty()) {
        cout << "Queue is empty." << endl;
        return 0;
    } else {
        return front;
    }
}

template<class t>
t Queue<t>::get_front_v() {
    if (is_empty()) {
        cout << "Queue is empty." << endl;
        return t();  
    } else {
        return arr[get_front_i()];
    }
}

template<class t>
int Queue<t>::get_size() {
    if (is_empty()) {
        cout << "Queue is empty." << endl;
        return 0;
    } else {
        return count;
    }
}

template<class t>
int Queue<t>::get_rear_i() {
    if (is_empty()) {
        cout << "Queue is empty." << endl;
        return -1;
    } else {
        return rear;
    }
}

template<class t>
t Queue<t>::get_rear_v() {
    if (is_empty()) {
        cout << "Queue is empty." << endl;
        return t();  // safer
    } else {
        return arr[get_rear_i()];
    }
}

template<class t>
void Queue<t>::clear() {
    count = 0;
    front = 0;
    rear = -1;
}

template<class t>
void Queue<t>::display() {
    if (is_empty()) {
        cout << "Queue is empty !!" << endl;
    } else {
        int size = count;
        int curr = front;
        cout << "[ ";
        while (size > 0) {
            cout << arr[curr];
            if (size > 1) cout << " , ";
            curr = (curr + 1) % MAX_SIZE;
            size--;
        }
        cout << " ]" << endl;
    }
}

template<class t>
int Queue<t>::search(t val) {
    int output = -1;
    if (is_empty()) {
        cout << "Queue is empty !!" << endl;
    } else {
        int size = count;
        int curr = front;
        while (size > 0) {
            if (arr[curr] == val) {
                output = curr;
                break;
            }
            curr = (curr + 1) % MAX_SIZE;
            size--;
        }
    }
    if (output == -1) {
        cout << "Target wasn't found in queue." << endl;
    }
    return output;
}

int main() {
    Queue<string> q;
    q.enqueue("Ahmed");
    q.enqueue("Mazen");
    q.dequeue();
    q.dequeue();
    q.enqueue("Ameer");
    q.enqueue("Othman");
    q.enqueue("Mostafa");
    q.enqueue("Ali");
    string rear = q.get_rear_v();
    string front = q.get_front_v();
    int target = q.search("Ali");
    q.display();
    cout << "Ali is in index " << target << endl;
    cout << "Front : " << front << " at index " << q.get_front_i() << " ." << endl;
    cout << "Rear : " << rear << " at index " << q.get_rear_i() << " ." << endl;
    q.clear();
    q.display();

    return 0;
}
