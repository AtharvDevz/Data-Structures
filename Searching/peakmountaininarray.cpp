#include<iostream>
using namespace std;

int peakIndexInMountainArray(int *arr[]) {
    
    int s = 0, e = (sizeof(arr)/sizeof(arr[0])) - 1 , mid;
    mid = ( s + e ) / 2 ;

    while(s < e){
        if(arr[mid] < arr[mid+1]){
            s = mid + 1 ;
        }else{
            e = mid ; 
        }
        mid = (s + e) / 2 ;
    }
    return mid ;
}