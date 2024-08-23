/* Provide Same Functionalities as static Array. We Do not use it Extensively.
 */
#include<iostream>
#include<array>
using namespace std;
int main(){
    array<int, 5> a = {1, 2,3,4,5};
    cout<<"a[2] : "<<a.at(2)<<endl;
    cout<<"a[0] : "<<a.front()<<endl;
    cout<<"a[4] : "<<a.back()<<endl;
    cout<<"Size = "<<a.size()<<endl;
    cout<<"\nTo Check if it is Empty : "<<a.empty()<<endl;
}