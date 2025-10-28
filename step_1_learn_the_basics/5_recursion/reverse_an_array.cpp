#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void reverse_array(int *left , int *right){
    if(left>=right){
        return;
    }
    swap(left, right);
    reverse(left+1, right-1);
    return;
}

void reverse_single_pointer(int i, int *left ,int n){
    if(i >= n/2){
        return;
    }
    swap(left+i, left+n-i-1);
    reverse_single_pointer(i+1, left, n);
    return;
}


int main(){
    vector<int> nums;
    int n;
    int x;

    cout<<"enter the number of elements"<<endl;
    cin>>n;

    cout<<"Enter the elements"<<endl;

    for(int i=0; i<n; i++){
        cin >> x;
        nums.push_back(x);
    }

    // reverse(&nums[0], &nums[n-1]);
    // reverse_array(&nums, &nums[n-1]);
    reverse_single_pointer(0, &nums[0], n);

    cout<<"following is the reversed array"<<endl;
    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
}