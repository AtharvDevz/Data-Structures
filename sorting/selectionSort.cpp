#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void selectionSort(int arr[], int n)
{
    for (int j = 0; j < n-1; j++)
    {
        int minIndex = j; // Keep track of the index of the minimum element

        for (int i = j + 1; i < n; i++)
        {
            if (arr[i] < arr[minIndex])
            {

                minIndex = i; // Update the index of the minimum element
            }
        }

        int temp = arr[j];
        arr[j] = arr[minIndex];
        arr[minIndex] = temp;
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
    selectionSort(array, 7);
    cout << "Array After Sorting : " << endl;
    display(array, 7);
}