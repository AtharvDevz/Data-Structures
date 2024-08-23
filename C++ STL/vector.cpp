#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> v;
    cout<<"Capacity : "<<v.capacity()<<endl;
    v.push_back(5);
    cout<<"Capacity : "<<v.capacity()<<endl;
    v.push_back(7);
    v.push_back(3);
    v.push_back(9);
    cout<<"size : "<<v.size()<<endl;
    cout<<"Before poping";  
    for(int i : v){
        cout<<i<<" ";
    }
    cout<<"After Poping Operation : "<<endl;
    v.pop_back();
    for(int i : v){
        cout<<i<<" ";
    }
    cout<<"Again Pop_Back ;"<<endl;
    v.pop_back();
    for(int i : v){
        cout<<i<<" ";
    }
    v.clear();
    cout<<"After Clear : "<<endl;
    for(int i : v){
        cout<<i<<" ";
    }
    return 0;
}