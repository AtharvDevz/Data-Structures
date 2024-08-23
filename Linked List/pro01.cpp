// Binary Operations on Linked List
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node* tail;

    Node(){
        this->prev = nullptr;
        this->next = nullptr;
    }
    Node(int data){
        this->data = data;
        this->next= nullptr;
    }
};

void createNode(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    newNode ->next = nullptr ;
    newNode->next = nullptr ;
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }else{
        Node *curr = head ;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
        tail->prev = tail ;  
        tail = newNode;
    }
}

void display(Node* &head){
    if(head == nullptr){
        cout<<"List is Empty\n";
    }
    Node* temp = head ;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next ;
    }
    cout<<endl;
}

void onescomplement(Node* &head, Node* &tail){
    Node* curr = head;
    while(curr != nullptr){
        curr->data = 1 - curr -> data ;
        curr = curr -> next;
    }
}

void twoscomplement(Node* &head, Node* &tail){
    int carry = 1, sum ;
    Node* temp = tail ;
    while( ( carry != 0 && temp != nullptr )){
        sum = carry + temp ->data ;
        temp ->data = (sum & 1) ;
        carry = sum / 2 ;
        temp = temp -> prev ;
    }
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head ;
        head->prev = newNode ;
        head = newNode;
    }
}

int main() {
    Node* head = nullptr; 
    Node* tail = nullptr; 
    cout<<"Kya Program Chala Raha hai"<<endl;
    for (int i = 0; i < 3; ++i) {
        int data;
        cin >> data;
        createNode(head, tail, data);
    }
    cout << "\nBinary Number : ";
    display(head);

    onescomplement(head, tail);
    cout<<"\n1's Complement : ";
    display(head);

    twoscomplement(head, tail);
    cout<<"\n2's Complement : ";
    display(head);
    
    return 0;
}
