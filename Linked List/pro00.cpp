#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->next = NULL ;
    }
    Node(int data){
        this->data = data ;
        this->next = NULL ;
    }


};

void insertAtHead(Node* &head, int val){
    Node *temp = new Node(val);
    temp -> next = head;
    head = temp ;
}

void insertAtEnd(Node* &head, int val){
    Node *newNode = new Node(val);
    if(head == nullptr){
        head = newNode ;
        return ;
    }
    Node *temp = head ;
    while(temp->next != NULL){
        temp = temp->next ;
    }
    temp->next = newNode ;
}

void insertAtPos(Node *&head, int val, int pos){
    Node *newNode = new Node(val);
    if(pos == 1){
        insertAtHead(head, val);
        return ;
    }
    Node *temp = head ;
    for (int i = 1; i < pos - 1 ; i++){
        temp = temp->next ;
    }
    newNode->next = temp->next ;
    temp->next = newNode ;
    
}

void deleteAtHead(Node* &head){ 
    if(head == NULL){
        cout<<"Queue is Empty\n";
    }
    head = head->next; 
}

void deleteAtEnd(Node* &head){
    if(head == NULL){
        cout<<"Queue is Empty\n";
    }
    Node *temp = head ;
    while((temp->next)->next != NULL){
        temp = temp->next ;
    }
    temp->next = NULL;
}

void deleteAtPos(Node* &head, int pos){
    if(head == NULL){
        cout<<"Queue is Empty\n";
    }
        Node *temp = head;
    if(pos == 1){
        deleteAtHead(head);
    }
    int i = 1;
    while( i < pos - 1){
        temp = temp->next;
        i++;
    }
    temp->next = (temp->next)->next ;
}

void print(Node* &head){
    Node* temp = head ;
    if(head == NULL){
        cout<<"List is Empty";
        return ;
    }
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next ;
    }
    cout<<endl;
    delete temp;
}

Node* join(Node* head1, Node* head2){
    if(head1 == NULL){
        return head2 ;
    }
    Node* temp = head1 ;

    while((temp->next) != NULL){
        temp = temp->next ;
    }
    temp->next = head2 ;
    return head1 ;
}

int main(){
    Node *N1 = new Node(1);
    Node *N2 = new Node(10);
    insertAtHead(N1, 2);
    insertAtHead(N1,4);
    insertAtHead(N1, 3);
    print(N1);

    insertAtEnd(N1,6);
    print(N1);

    insertAtPos(N1, 18, 6) ;
    print(N1);

    deleteAtHead(N1);
    print(N1);

    deleteAtEnd(N1);
    print(N1);

    deleteAtPos(N1, 3);
    print(N1);


    cout<<"N2 = ";
    print(N2);
    Node* N3 = new Node;
    N3 = join(N1, N2);
    cout<<"N3 = ";
    print(N3);

    cout<<"N1 = ";
    print(N1);

    return 0;
}