#include <iostream>
#include <string>
using namespace std;
template<class t>
class Queue{
    private:
        struct Node{
            t value;
            Node* next;
        };
        Node* front;
        Node* rear;
        int length;
    public:
        Queue();
        bool is_empty();
        void enqueue(t val);
        t dequeue();
        t get_front();
        t get_rear();
        int get_size();
        void clear();
        void display();
        int search(t val);
};
template<class t>
Queue<t>::Queue(){
    front = new Node;
    rear = new Node;
    length = 0;
}
template<class t>
bool Queue<t>::is_empty(){
    if(length == 0)
        return true;
    else
        return false;
}
template<class t>
void Queue<t>::enqueue(t val){
    Node* temp = new Node{val , nullptr};
    if(is_empty()){
        front = rear = temp;
    }else{
        rear->next = temp;
        rear = temp;
    }
    this->length++;
}
template<class t>
t Queue<t>::dequeue(){
    if(is_empty()){
        cout<<"Queue is empty on dequeue !!"<<endl;
        return t(); // return default value
    }
    Node* temp = front;
    t output = temp->value;
    front = front->next;
    delete temp;
    length--;
    if(length == 0){
        rear->next == nullptr;
    }
    return output;
}
template<class t>
t Queue<t>::get_front(){
    if(is_empty()){
        cout<<"Queue is empty."<<endl;
        return 0; 
    }else{
        return front->value;
    }
}
template<class t>
int Queue<t>::get_size(){
    if(is_empty()){
        cout<<"Queue is empty."<<endl;
        return t(); // return default value
    }else{
        return length;
    }
}
template<class t>
t Queue<t>::get_rear(){
    if(is_empty()){
        cout<<"Queue is empty."<<endl;
        return t(); // return default value 
    }else{
        return rear->value;
    }
}
template<class t>
void Queue<t>::clear(){
    while(front!=nullptr){
        Node* temp = front;
        front = front->next;
        delete temp;
        length--;
    }
    rear = nullptr;
    length=0;
}
template<class t>
void Queue<t>::display(){
    if(is_empty()){
        cout<<"Queue is empty !!"<<endl;
    }else{
        int size = this->length;
        Node* curr = this->front;
        cout<<"[ ";
        while(size > 0){
            if(size==1){
                cout<<curr->value;
            }else{
                cout<<curr->value<< " , ";
            }
            curr = curr->next;
            size--;
        }
        cout<<" ]"<<endl;
    }
}
template<class t>
int Queue<t>::search(t val){
    int output = -1;
    if(is_empty()){
        cout<<"Queue is empty !!"<<endl;
    }else{
        int size = 1;
        Node* curr = front;
        while(size < length+1){
            if(curr->value == val){
                output = size;
                break;
            }
            curr = curr->next;
            size++;
        }
    }
    if(output == -1){
        cout<<"Target wasnt found in queue ."<<endl;
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
    string rear = q.get_rear();
    string front = q.get_front();
    int target = q.search("Ali");
    q.display();
    cout<<"Ali is name number "<<target<<endl;
    cout<<"Front : "<<front<<endl;
    cout<<"Rear : "<<rear<<endl;
    q.clear();
    q.display();
    
    return 0;
}