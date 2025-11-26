#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the size of the array: "<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=1; i<n; i++){
        if(arr[i]>=arr[i-1]){
            continue;
        }
        else{
            cout<<"The array is not sorted in non-decreasing order."<<endl;
            return 0;
        }
    }
    cout<<"The array is sorted in non-decreasing order."<<endl;
    return 0;
}