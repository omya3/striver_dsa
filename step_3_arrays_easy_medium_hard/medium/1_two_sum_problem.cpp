#include<iostream>

using namespace std;

void find_pair( vector<int>& arr, int target){
    int left = 0;
    int right = arr.size()-1;
    int sum = arr[left]+arr[right];
    while(left<right){
        if(sum<target){
            left++;
            sum = arr[left]+arr[right];
        }
        else if(sum>target){
            right--;
            sum = arr[left]+arr[right];
        }
        else{
            break;
        }
    }
    cout<<"The target sum is achieved by the two elements "<<arr[left]<<" and "<<arr[right]<<endl;
    return;
}

int main(){

    cout<<"Enter the size of the array: "<<endl;
    int n;
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array in sorted fashion: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int target_sum;
    cout<<"Enter the target sum you want to achieve"<<endl;
    cin>>target_sum;

    find_pair(arr, target_sum);

}