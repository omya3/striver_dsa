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

    int i, j;
    i = 0;
    for(j=1; j<n; j++){
        if(arr[j]!=arr[i]){
            i++;
            arr[i] = arr[j];
        }
    }

    cout<<"Array after removing duplicates: "<<endl;
    for(j=0; j<=i; j++){
        cout<<arr[j]<<" ";
    }
}