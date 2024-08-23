#include <iostream>
using namespace std;

template <class T>
class stack
{
    T size;
    T *arr;
    int p = -1;

public:
    stack()
    {
    }
    stack(int Size)
    {
        this->size = Size;
        arr = (T *)malloc(this->size * (sizeof(T)));
    }

    bool isEmpty()
    {
        if (p == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (p == size - 1)
        {
            return true;
        }
        return false;
    }

    int capacity()
    {
        return size;
    }

    void push(int val)
    {
        p++;
        arr[p] = val;
    }

    void pop()
    {
        p = p - 1;
    }

    int top()
    {
        return this->arr[p];
    }

    T peek(int index)
    {
        return arr[size - index];
    }

    void display()
    {
        cout << "\nStack : ";
        for (int i = p; i >= 0; i--)
        {
            cout << " " << arr[i];
        }
    }

    int stackTop()
    {
        return arr[p];
    }
    int stackBottom()
    {
        return arr[0];
    }
};

int main()
{
    stack<char> s1(6);

    s1.push('A');
    s1.push('B');
    s1.push('C');

    s1.display();

    s1.pop();
    s1.pop();

    s1.display();
}