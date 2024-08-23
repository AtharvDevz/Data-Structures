#include<iostream>
using namespace std;

int binarySearch(int arr[], int key, int s, int e){
    
    while (s <= e)
    {
        int mid = (s + e)/2; 
        if(arr[mid] < key){
            s =  mid + 1;
        }else if(arr[mid] > key){
            e = mid - 1;
        }else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int array[5] = {3, 7, 9, 13, 34};
    int result = binarySearch(array,7,0,4);

    if(result != -1){
        cout<<"result : "<<result;
    }else{
        cout<<"\n Element is Not Present in an Array ";
    }
}