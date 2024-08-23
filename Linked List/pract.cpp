#include<iostream>
using namespace std;

class Node{
    int data;
    Node* next;


    public:
    Node(int val){
        this->data = val ;
        this->next = nullptr;
    }

    void insertAtHead(Node* head, int val){
        Node *newNode = new Node(val) ;
        newNode->next = head ;
        head = newNode ;
    }
};

int main(){
    
    return 0;
}