#include<iostream>

using namespace std;

void swap(int arr[],int i ,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

void selection_sort(int arr[],int n){

    int min = 0;
    for(int i=0; i<n-1; i++){
        min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr, i, min);
    }
    return;
}

int main(){
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>> n;
    int arr[n];

    cout<<"Enter the array elements"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    selection_sort(arr, n);

    cout<<"Following is the sorted array";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}