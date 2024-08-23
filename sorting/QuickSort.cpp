/* #include<iostream>
using namespace std;
void quickSort(int arr[],int s, int e){
    int mid = (s + e) / 2 , i=s , j=e;
    while(arr[i] < arr[mid]){
        i++;
    }
    while(arr[j] > arr[mid]){
        j--;
    }

    if(i < j){
        int temp = arr[i];
        arr[i] = arr[j] ; 
        arr[j] = arr[i] ;
        
    }else if(j > i){
        int temp = arr[i];
        arr[i] = arr[mid] ; 
        arr[mid] = arr[i] ;
        quickSort(arr,s,mid-1);
        quickSort(arr, mid+1,e);
    }
}
int main(){
    int my_array[10] = {6, 5, 8, 9, 3, 6, 15, 12, 16};
    cout<<"Sorted Array : ";
    quickSort(my_array, 0, 10);
    for(int i=0;i<10;i++){
        cout<<my_array[i];
    }

} */

#include <iostream>  
using namespace std;  

int partition (int a[], int start, int end)  
{  
    int pivot = a[end]; // pivot element  
    int i = (start - 1);  
    for (int j = start; j <= end - 1; j++)  
    {   
        if (a[j] < pivot)  
        {  
            i++;  
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
        }  
    }  
    int t = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t;  
    return (i + 1);  
}  

void quick(int a[], int start, int end)  
{  
    if (start < end)  
    {  
        int p = partition(a, start, end);  
        quick(a, start, p - 1);  
        quick(a, p + 1, end);  
    }  
}   
void printArr(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout<<a[i]<< " ";  
}  
int main()  
{  
    int a[] = { 23, 8, 28, 13, 18, 26 };  
    int n = sizeof(a) / sizeof(a[0]);  
    cout<<"Before sorting array elements are - \n";  
    printArr(a, n);  
    quick(a, 0, n - 1);  
    cout<<"\nAfter sorting array elements are - \n";    
    printArr(a, n);        
    return 0;  
}  