// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
template <class t>
class DoublyLinkedList{
    private:
        struct Node{
            t value;
            Node* next , *prev;
        };
        Node* head , *tail;
        int size;
    public:
        DoublyLinkedList();
        bool is_empty();
        void insert_first(t val);
        void insert_last(t val);
        void insert_at(int pos , t val);
        t remove_first();
        t remove_last();
        t remove_at(int pos);
        t remove_val(t val);
        void display();
        void display_rev();
};
template<class t>
DoublyLinkedList<t>::DoublyLinkedList(){
    head = tail = nullptr;
    size = 0;
}
template<class t>
bool DoublyLinkedList<t>::is_empty(){
    return !size;
}
template<class t>
void DoublyLinkedList<t>::insert_first(t val){
    Node* new_node = new Node{val,nullptr,nullptr}; 
    if(is_empty()){
        head = tail = new_node;
    }else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    size++;
}
template<class t>
void DoublyLinkedList<t>::insert_last(t val){
    Node* new_node = new Node{val,nullptr,nullptr}; 
    if(is_empty()){
        head = tail = new_node;
    }else{
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    size++;
}
template<class t>
void DoublyLinkedList<t>::insert_at(int pos , t val){
    if(pos < 0 || pos > size){
        cout<<"Invalid Position !!"<<endl;
        return;
    }
    if(pos == 0){
        insert_first(val);
        return;
    }
    else if(pos == size){
        insert_last(val);
        return;
    }
    else{
        Node* new_node=new Node{val , nullptr, nullptr};
        Node* curr = head;
        int i = 0;
        while(i < pos-1){
            curr = curr->next;
            i++;
        }
        new_node->next = curr->next;
        curr->next->prev = new_node;
        new_node->prev = curr;
        curr->next = new_node;
        size++;
    }
}
template<class t>
t DoublyLinkedList<t>::remove_at(int pos ){
    if(pos < 0 || pos >= size){
        cout<<"Invalid Position !!"<<endl;
        return t();
    }
    if(pos == 0){
        return remove_first();
    }
    else if(pos == size-1){
        return remove_last();
    }
    else{
        Node* curr = head;
        int i = 0;
        while(i < pos){
            curr = curr->next;
            i++;
        }
        Node* before = curr->prev;
        Node* after = curr->next;
        before->next = after;
        after->prev = before;
        t output = curr->value;
        delete curr;
        size--;
        return output;
    }
}
template <class t>
t DoublyLinkedList<t>::remove_first(){
    if(is_empty()){
        cout<<"List is empty cannot remove first ."<<endl;
        return t();
    }
    Node* temp = head;
    t output = temp->value;
    head = head->next;
    if(head){
        head->prev = nullptr;// list isnt empty.
    }else{
        tail = nullptr;// list is empty.
    }
    delete temp;
    size--;
    return output;
}
template <class t>
t DoublyLinkedList<t>::remove_last(){
    if(is_empty()){
        cout<<"List is empty cannot remove last ."<<endl;
        return t();
    }else{
        Node* temp = tail;
        tail = tail->prev;
        if(tail){
            tail->next = nullptr;// list isnt empty.
        }else{
            head = nullptr;// list is empty.
        }
        t output = temp->value;
        delete temp;
        size--;
        return output;
    }
}
template <class t>
t DoublyLinkedList<t>::remove_val(t val){
    if(is_empty()){
        cout << "List is empty cant remove value . "<<endl;
        return t();
    }
    Node* curr = head;
    
    while(curr && curr->value != val){
        curr = curr->next;
    }
    if(!curr){
        cout<<"Value "<< val <<" wasnt found in list."<<endl;
        return t();
    }else if(curr == head){
        return remove_first();    
    }else if(curr == tail){
        return remove_last();    
    }else{
        Node*before = curr->prev;
        Node* after = curr->next;
        
        before->next = after;
        after->prev = before;
        
        t output = curr->value;
        delete curr;
        size --;
        return output;
    }
}
template <class t>
void DoublyLinkedList<t>::display(){
    Node* curr = head;
    cout<<"[ ";
    while(curr != nullptr){
        if(curr->next == nullptr){
            cout<<curr->value;
        }else{
            cout<<curr->value<<" , ";
        }
        curr = curr->next;
    }
    cout<<" ]"<<endl;
}
template <class t>
void DoublyLinkedList<t>::display_rev(){
    Node* curr = tail;
    cout<<"[ ";
    while(curr != nullptr){
        if(curr->prev == nullptr){
            cout<<curr->value;
        }else{
            cout<<curr->value<<" , ";
        }
        curr = curr->prev;
    }
    cout<<" ]"<<endl;
}
int main() {
    DoublyLinkedList<int> dl ;
    dl.remove_val(20);
    dl.insert_first(300);
    dl.insert_last(400);
    dl.insert_at(1,500);
    dl.insert_at(2,700);
    dl.insert_at(3,800);
    dl.insert_at(0,100);
    dl.insert_at(5,1000);
    dl.remove_val(20);
    dl.display();
    int first = dl.remove_at(0);
    cout<< "Removing first value : "<<first<<endl;
    dl.display();
    int last = dl.remove_at(5);
    cout<< "Removing last value : "<<last<<endl;
    dl.display();
    int mid = dl.remove_at(2);
    cout<< "Removing value : " << mid <<" at position 2 ."<<endl;
    dl.display();
    cout<<"Reversed List : "<<endl;
    dl.display_rev();
    first = dl.remove_first();
    cout<< "Removing first value : "<<first<<endl;
    dl.display();
    last = dl.remove_last();
    cout<< "Removing last value : "<<last<<endl;
    dl.display();
    int val = dl.remove_val(800);
    cout<<"Removing value : "<<val<<" ."<<endl;
    dl.display();
    return 0;
}