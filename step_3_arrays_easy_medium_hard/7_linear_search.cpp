#include<iostream>

using namespace std;

int main(){
     cout << "Enter the size of the array: " << endl;
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout<<"Enter the element to search: "<<endl;
    cin>>x;

    for(int i=0; i<n; i++){
        if(arr[i]==x){
            cout<<"Element found at index: "<<i<<endl;
            return 0;
        }
    }
    cout<<"Element not found in the array"<<endl;
}