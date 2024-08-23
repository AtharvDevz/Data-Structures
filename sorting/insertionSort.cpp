#include <iostream>
using namespace std;

void insertionSort(int *arr, int n){
    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i - 1 ;
        while(j >= 0 && temp < arr[j]){
            arr[j+1] = arr[j] ;
            j = j - 1;
        }
        arr[j + 1] = temp ;
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Array[" << i << "] = " << arr[i] << endl;
    }
}
int main()
{
    int array[7] = {34, 1, 57, 25, 21, 14, 19};
    cout << "Array Before Sorting : " << endl;
    display(array, 7);
    insertionSort(array, 7);
    cout << "Array After Sorting : " << endl;
    display(array, 7);
}