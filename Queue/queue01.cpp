// Implementation of Queue using Array
#include <iostream>
using namespace std;

struct queue
{
    int size;
    int F;
    int B;
    int *arr;
};

void createQueue(struct queue *q, int size)
{
    q->size = size;
    q->F = -1;
    q->B = -1;
    q->arr = (int *)malloc(q->size * (sizeof(int)));
}

void enqueue(struct queue *q, int data)
{
    if (q->B == (q->size - 1))
    {
        cout << "Queue is Full";
    }
    else
    {
        q->B = q->B + 1;
        q->arr[q->B] = data;
    }
}

void dequeue(struct queue *q)
{
    if (q->F == q->B)
    {
        cout << "Queue is Empty";
    }
    else
    {
        q->arr[q->F] = NULL ;
        q->F = q->F + 1;
    }
}

bool isFull(struct queue *q)
{
    if (q->B == (q->size - 1))
    {
        return true;
    }
    return false;
}

bool isEmpty(struct queue *q)
{
    if (q->F == q->B)
    {
        return true;
    }
    return false;
}

void display(struct queue *q)
{
    cout << "\nQueue : ";
    if (q->F == q->B)
    {
        cout << "\nQueue is Empty";
    }
    else
    {
        int i = q->F + 1;
        for (i; i <= q->B; i++)
        {
            cout << q->arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    struct queue q;
    createQueue(&q, 5);

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
            enqueue(&q, x);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
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
