#include <bits/stdc++.h>
using namespace std;
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void bubbleSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < (n - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i << "] : " << arr[i] << endl;
    }
}

int main()
{
    int array[7] = {34, 1, 57, 25, 21, 14, 19};
    cout << "Array Before Sorting : " << endl;
    display(array, 7);
    bubbleSort(array, 7);
    cout << "Array After Sorting : " << endl;
    display(array, 7);
}
