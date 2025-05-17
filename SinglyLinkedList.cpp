#include <iostream>
#include <string>
using namespace std;
template<class t>
class LinkedList{
    private:
        struct Node{
            t value ; 
            Node* next;
        };
        Node* head;
        Node* tail;
        int length;
    public:
        LinkedList();
        bool is_empty();
        void insert_first(t val);
        void insert_last(t val);
        void insert_at_pos(int pos , t val);
        t remove_first();
        t remove_last();
        t remove_at_pos(int pos);
        void display();
        void reverse();
        int search(t val);
};
template <class t>
LinkedList<t>::LinkedList(){
    head = tail = nullptr;
    length=0;
}
template<class t>
bool LinkedList<t>::is_empty(){
    return !length;
}
template<class t>
void LinkedList<t>::insert_first(t val){
    Node* new_node = new Node{val , nullptr};
    if(is_empty()){
        head = tail = new_node;
    }else{
        new_node->next = head;
        head = new_node;
    }
    length++;
}
template<class t>
t LinkedList<t>::remove_first(){
    t output ;
    if(is_empty()){
        cout<<"List is Empty cannot remove first ."<<endl;
        return t();
    }else{
        Node* temp = head;
        head = head->next;
        output = temp->value;
        delete temp;
        length--;
        if(is_empty()){
            tail = nullptr;
        }
    }
    return output;
}
template<class t>
void LinkedList<t>::insert_last(t val){
    Node* new_node = new Node{val , nullptr};
    if(is_empty()){
        head = tail = new_node;
    }else{
        tail->next = new_node;
        tail = new_node;
    }
    length++;
}
template<class t>
t LinkedList<t>::remove_last(){
    t output;
    if(is_empty()){
        cout<<"List is Empty cannot remove last ."<<endl;
        return t();
    }else if (length == 1){
        output=remove_first();
    }else{
        Node* temp = head;
        while(temp->next!=tail){
            temp = temp->next;
        }
        tail = temp;
        temp = temp->next;
        output = temp->value;
        delete temp;
        tail->next = nullptr;
        length--;
    }
    return output;
}
template<class t>
void LinkedList<t>::insert_at_pos(int pos,t val){
    if(pos < 0 || pos > length){
        cout<<"Invalid Position !!"<<endl;
        return;
    }
    if(pos == 0){
        insert_first(val);
        return;
    }
    else if(pos == length){
        insert_last(val);
        return;
    }
    else{
        Node* new_node=new Node{val , nullptr};
        Node* curr = head;
        int i = 0;
        while(i < pos-1){
            curr = curr->next;
            i++;
        }
        new_node->next = curr->next;
        curr->next = new_node;
        length++;
    }
}
template<class t>
t LinkedList<t>::remove_at_pos(int pos){
    if(pos < 0 || pos >= length){
        cout<<"Invalid Position !!"<<endl;
        return t();
    }
    t output ;
    if(pos == 0){
        return remove_first();
    }
    else if(pos == length-1){
        return remove_last();
    }
    else{
        Node* temp = nullptr;
        Node* curr = head;
        int i = 0;
        while(i < pos-1){
            curr = curr->next;
            i++;
        }
        temp = curr->next;
        curr->next = curr->next->next;
        t output = temp->value;
        delete temp;
        length--;
        return output;
    }
}
template <class t>
void LinkedList<t>::display(){
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
void LinkedList<t>::reverse(){
    Node* before = nullptr;
    Node* after = nullptr;
    Node* curr = head;
    tail = head;
    while(curr){
        after = curr->next;
        curr->next = before;
        before = curr;
        curr = after;
    }
    head = before;
}
template <class t>
int LinkedList<t>::search(t val){
    Node* curr = head;
    int count = 0;
    while(curr != nullptr){
        if(curr->value == val){
            return count;
        }else{
            count++;
            curr = curr->next;
        }
    }
    cout<<"Value isnt in list ."<<endl;
    return -1;
}
int main() {
    LinkedList<string> ll;
    ll.insert_last("Mazen");
    ll.insert_first("Kareem");
    ll.insert_first("Ali");
    ll.display();
    ll.insert_at_pos(3,"Ebrahim");
    ll.display();
    ll.insert_at_pos(4,"Sameh");
    ll.display();
    ll.insert_at_pos(2,"Sameer");
    ll.display();
    ll.reverse();
    ll.display();
    string first = ll.remove_first();
    cout<<first<<" has been removed."<<endl;
    ll.display();
    int search = ll.search("Sameer");
    cout <<"Sameer is in index "<<search<<" ."<<endl;
    string item = ll.remove_at_pos(search);
    cout<<item<<" has been removed."<<endl;
    ll.display();
    string last = ll.remove_last();
    cout<<last<<" has been removed."<<endl;
    ll.display();
    
    return 0;
}