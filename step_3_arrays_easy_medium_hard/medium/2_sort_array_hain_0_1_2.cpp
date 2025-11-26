#include<iostream>
using namespace std;

void swap(vector<int> &arr, int x, int y)
{
    int temp;
    temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
    return;
}

void dutch_national_flag(vector<int> &arr){
    int low, mid, high;
    low = mid = arr[0];
    high = arr.size()-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr, mid, low);
            mid++;
            low++;
        }
        if(arr[mid]==1){
            mid++;
        }
        if(arr[mid]==2){
            swap(arr, mid, high);
            high--;
        }
    }
    return;

}

int main(){
    cout<<"Enter the size of the array: "<<endl;
    int n;
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements (0,1,2) of the array in unsorted fashion: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    dutch_national_flag(arr);
    cout<<"Following is the array in sorted fashion: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}