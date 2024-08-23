#include <iostream>
using namespace std;

template<class T>
class stack
{
    int size;
    T *arr;
    int p = -1;

public:
    stack(int Size)
    {
        this->size = Size;
        arr = (T *)malloc(this->size *(sizeof(T)));
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

    void display()
    {
        cout << "\nStack : " ;
        for (int i = p; i >= 0; i--)
        {
            cout << " " << arr[i] ;
        }
    }
};

int length(string str1)
{
    int i = 0;
    for (int ch : str1)
    {
        i++;
    }
    return i;
}

string reverseString(string str1)
{
    int len = length(str1);
    stack<char> s1(len);

    for (char ch : str1)
    {
        s1.push(ch);
    }
    cout << "\n s1.size :  " << s1.capacity();
    s1.display();

    string reversedString = "";

    do
    {
        char ch;
        ch = s1.top();
        reversedString = reversedString + ch;
        s1.pop();
    }while (!s1.isEmpty());
    return reversedString;
}

bool isPallindrome(string str)
{
    int len = str.length();
    for (int i = 0; i < (len / 2); ++i)
    {
        if (str[i] != str[len - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string name = "NAYAN";
    string reversedString = reverseString(name);
    cout << "\nreverseString : " << reversedString << endl;

    if (isPallindrome(name))
    {
        cout << "\nPallindrome";
    }
    else
    {
        cout << "\nNot pallindrome";
    }
}