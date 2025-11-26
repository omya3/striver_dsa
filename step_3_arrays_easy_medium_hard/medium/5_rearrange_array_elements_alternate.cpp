#include<iostream>
using namespace std;

vector<int> rearrange_alternatively(vector<int> &nums){
    int n = nums.size();
    vector<int> res(n);
    int pos_idx = 0, neg_idx = 1;
    for(int i = 0; i < n; ++i) {
        if(nums[i] > 0) {
            res[pos_idx] = nums[i];
            pos_idx += 2;
        } else {
            res[neg_idx] = nums[i];
            neg_idx += 2;
        }
    }
    return res;
}

int main(){
    cout << "Enter the size of the array: " << endl;
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    rearrange_alternatively(arr);
}