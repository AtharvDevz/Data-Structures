#include<iostream>
using namespace std;

class circularQueue{
    public:
    int data;
    int F;
    int B;
    int size;
    int *arr;

    circularQueue(){
        F = -1;
        B = -1;
    }

    circularQueue(int Size){
        size = Size ;
        F = -1 ;
        B = -1 ;
        arr = (int*)malloc((size)*(sizeof(int)));
    }

    bool isFull(){
        if((B + 1) % size == F){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(F == -1){
            return true;
        }
        return false;
    }

    void enqueue(int val){
        if(isFull()){
            cout<<"Queue is Full\n";
        }else if(isEmpty()){
            F = 0;
            B = 0 ;
            arr[F] = val;
        }else{
            B = (B + 1) % size ;
            arr[B] = val ;
        }
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty\n";
        }else{
            F = (F + 1) % size ;
        }
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is Empty\n";
        }else{
            int i = F;
            if(F == B){
                cout<<arr[i];
            }
            cout<<arr[i]<<" ";
            do{
                i = (i + 1) % size ;
                cout<<arr[i]<<" ";
            }while( i != B);
        }
    }
};

int main(){
    int size;
    cout<<"Enter Size of Queue : ";
    cin>>size;
    circularQueue q(size);
    

    cout << "******** Menu ********" << endl;
    cout << "1. Add job" << endl;
    cout << "2. Remove job" << endl;
    cout << "3. Display Jobs" << endl;
    cout << "4. Exit" << endl;

    while (true)
    {
        int choice, x;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter no : ";
            cin >> x;
            q.enqueue(x);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            return 0;
            break;
        default:
            cout << "Invalid Choice\n";
        }
        cout << "\n";
    }
}