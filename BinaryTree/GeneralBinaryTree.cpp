// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <queue>
#include<string>
using namespace std;
template<class t>
class BinaryTree{
    private:
        struct Node{
            t value;
            Node* left;
            Node* right;
        };
        Node* root;
        void pre_order(Node* node);
        void in_order(Node* node);
        void post_order(Node* node);
    public:
        BinaryTree();
        void pre_order();
        void in_order();
        void post_order();
        void level_order();
        void insert(t val); 
        t del(t val); 
};
template <class t>
BinaryTree<t>::BinaryTree(){
    root = nullptr;
}
template<class t>
void BinaryTree<t>::pre_order(Node* node){
    if(!node)
        return;
    cout<<node->value<<" ";
    pre_order(node->left);
    pre_order(node->right);
}
template<class t>
void BinaryTree<t>::pre_order(){
    if(!root)
        cout<<"Tree is empty."<<endl;
    else{
        cout<<"[ ";
        pre_order(root);
        cout<<"]"<<endl;
    }
}
template<class t>
void BinaryTree<t>::in_order(Node* node){
    if(!node)
        return;
    in_order(node->left);
    cout<<node->value<<" ";
    in_order(node->right);
}
template<class t>
void BinaryTree<t>::in_order(){
    if(!root)
        cout<<"Tree is empty."<<endl;
    else{
        cout<<"[ ";
        in_order(root);
        cout<<"]"<<endl;
    }
}
template<class t>
void BinaryTree<t>::post_order(Node* node){
    if(!node)
        return;
    post_order(node->left);
    post_order(node->right);
    cout<<node->value<<" ";
}
template<class t>
void BinaryTree<t>::post_order(){
    if(!root)
        cout<<"Tree is empty."<<endl;
    else{
        cout<<"[ ";
        post_order(root);
        cout<<"]"<<endl;
    }
}
template<class t>
void BinaryTree<t>::level_order(){
    if(!root){
        cout<<"Tree is empty."<<endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    cout<<"[ ";
    while(!q.empty()){
        Node* curr = q.front();
        cout<<curr->value<<" ";
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
        q.pop();
    }
    cout<<" ]"<<endl;
}
template<class t>
void BinaryTree<t>::insert(t val){
    if(!root){
        root = new Node{val , nullptr , nullptr};
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        if(curr->left){
            q.push(curr->left);
        }else{
            curr->left=new Node{val , nullptr , nullptr};
            return;
        }
        if(curr->right){
            q.push(curr->right);
        }else{
            curr->right=new Node{val , nullptr , nullptr};
            return;
        }
        q.pop();
    }
}
template<class t>
t BinaryTree<t>::del(t val){
    if(!root){
        cout<<"Tree is empty , cant delete !!"<<endl;
        return t();
    }
    
    if(root->right == nullptr && root->left == nullptr && root->value == val){
        t output = root->value;
        delete root;
        root = nullptr;
        return output;
    }
    
    Node* target = nullptr;
    Node* curr = nullptr;
    Node* parent_of_deepest_node = nullptr;
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        curr = q.front();
        q.pop();
        if(curr->value == val)
            target = curr;
        if(curr->left){
            q.push(curr->left);
            parent_of_deepest_node = curr;
        }
        if(curr->right){
            q.push(curr->right);
            parent_of_deepest_node = curr;
        }
    }
    if(!target){
        cout<<"Value wasnt found in tree !!"<<endl;
        return t();
    }
    t output = target->value;
    target->value = curr->value;
    if(parent_of_deepest_node->left == curr){
        delete curr;
        parent_of_deepest_node->left = nullptr;
    }else if(parent_of_deepest_node->right == curr){
        delete curr;
        parent_of_deepest_node->right = nullptr;
    }
    return output;
}
int main() {
    BinaryTree<string> bt;
    bt.insert("Ahmed");
    bt.insert("Mostafa");
    bt.insert("Ali");
    bt.insert("Ameer");
    bt.insert("Ebrahim");
    bt.level_order();
    string del_val=bt.del("Ebrahim");
    if(!del_val.empty())
        cout<<"Deleting "<<del_val<<" ....."<<endl;
    bt.level_order();
    return 0;
}