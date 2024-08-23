/* #include<iostream>
using namespace std;
void swap(int i, int j){
    int temp = i;
    i = j ; 
    j = i ;
}

void quickSort(int arr[],int s, int e){
    int mid = (s + e) / 2 , i=s , j=e;
    if((e-s) <=1){
        if(arr[e] < arr[s]){
            swap(arr[e], arr[s]);
        }
        return ;
    }
    
    while(i!=j){
        while(arr[i] <= arr[mid]){
            i++;
        }
        while(arr[j] >= arr[mid]){
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
            
        }
    }
    quickSort(arr,s,mid-1);
    quickSort(arr, mid+1,e);
}

int main(){
    int my_array[10] = {6, 5, 8, 9, 3, 6, 15, 12, 16, 2};
    cout<<"\nOrignal Array : ";
    for(int i=0;i<10;i++){
        cout<<"\narr["<<i<<"] = "<<my_array[i];
    }
    cout<<"\nSorted Array : ";
    quickSort(my_array, 0, 10);
    for(int i=0;i<10;i++){
        cout<<"\narr["<<i<<"] = "<<my_array[i];
    }
    return 0;
} */

/* #include <iostream>
using namespace std;

void swap(int &i, int &j) {
    int temp = i;
    i = j;
    j = temp;
}

void quickSort(int arr[], int s, int e) {
    int mid = (s + e) / 2, i = s, j = e;
    if ((e - s) <= 1) {
        if (arr[e] < arr[s]) {
            swap(arr[e], arr[s]);
        }
        return;
    }

    while (i != j) {
        while (arr[i] <= arr[mid]) {
            i++;
        }
        while (arr[j] >= arr[mid]) {
            j--;
        }
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else if (j > i) {
            int temp = arr[i];
            arr[i] = arr[mid];
            arr[mid] = temp;
        }
    }
    quickSort(arr, s, mid - 1);
    quickSort(arr, mid + 1, e);
}

int main() {
    int my_array[10] = {6, 5, 8, 9, 3, 6, 15, 12, 16, 2};
    cout << "Original Array: ";
    for (int i = 0; i < 10; i++) {
        cout << "\narr[" << i << "] = " << my_array[i];
    }
    cout << "\nSorted Array: ";
    quickSort(my_array, 0, 9);
    for (int i = 0; i < 10; i++) {
        cout << "\narr[" << i << "] = " << my_array[i];
    }
    return 0;
}
 */

#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[ (low + high ) / 2];
    while (true) {
        while (arr[low] < pivot) {
            low++;
        }
        while (arr[high] > pivot) {
            high--;
        }
        if (low >= high) {
            return high;
        }
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

void quickSort(int arr[], int low, int high) {
    if (low > high) {
        return ; 
    }
    int pivotIndex = partition(arr, low, high);
    quickSort(arr, low, pivotIndex);
    quickSort(arr, pivotIndex + 1, high);
}

int main() {
    int my_array[10] = {6, 5, 8, 9, 3, 6, 15, 12, 16, 2};
    cout << "Original Array: ";
    for (int i = 0; i < 10; i++) {
        cout << "\narr[" << i << "] = " << my_array[i] << " ";
    }

    quickSort(my_array, 0, 9);

    cout << "\nSorted Array: ";
    for (int i = 0; i < 10; i++) {
        cout << "\narr[" << i << "] = " << my_array[i] << " ";
    }
    
    return 0;
}
