#include<iostream>
#include<cmath>

using namespace std;


void print_all_divisors(int x){
    vector<int> list_divisors;
    int j = 0;
    for(int i = 0; i<sqrt(x); i++){
        if(x%i==0){
            list_divisors.emplace_back(i);
            j = x/i;
            if(i!=j){
                list_divisors.emplace_back(j);
            }
        }
    }
    sort(list_divisors.begin(), list_divisors.end());
    for(auto it : list_divisors){ // yet another way to iterate for each loop
        cout<<it<<" "; // see that we do not need to dereference here
    }
    cout<<endl;
}

int main(){
    print_all_divisors(36);
    print_all_divisors(100);
    print_all_divisors(7);
}