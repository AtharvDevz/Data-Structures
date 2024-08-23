#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Array[" << i << "] = " << arr[i] << endl;
    }
}

void shellSort(int array[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}
/* 
void shellSort(int arr[], int n){
    for(int gap = n / 2; gap > 0 ; gap = gap / 2){
        for(int i = gap; i < n; i++){
            int temp = arr[i] ;
            int j = i ;
            while(j >= gap && arr[j - gap] > temp){
                arr[j] = arr[j - gap] ;
            }
            arr[j] = temp ;
        }
    }
}

def shellSort(arr, n):
    gap = gap // 2
    while(gap > 0):
        i  = gap
        for i in range(gap, n):
            temp = arr[i] ;
            j = i
            while(j >= gap and arr[j-gap] > temp):
                arr[j] = arr[j-gap]
                j = j - gap
            arr[j] = temp
        gap =  gap / 2
 */

int main()
{
    int array[7] = {34, 1, 57, 25, 21, 14, 19};
    cout << "Array Before Sorting : " << endl;
    display(array, 7);
    shellSort(array, 7);
    cout << "Array After Sorting : " << endl;
    display(array, 7);
}
int main()
{

    return 0;
}
