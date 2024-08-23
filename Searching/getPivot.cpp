#include<iostream>
using namespace std;

int getPivot(int arr[], int n){
    int s=0, e=n , mid = (s + e)/2;

    while(s < e){
        if( arr[mid] >= arr[0]){
            s = mid + 1;
        }else{
            e = mid;
        }
        mid = (s + e)/2 ;
    }
    return s;
}

int main(){
    int arr[7] = {4, 7, 8, 9, 11, 2, 7}, index;
    index = getPivot(arr, 7);
    cout<<"Pivot is At Index : "<<index;
}
