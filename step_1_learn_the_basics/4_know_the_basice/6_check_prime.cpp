#include<iostream>
#include<cmath>

using namespace std;


void check_prime(int x){
    vector<int> list_divisors;
    int j = 0;

    if (x <= 1) {
        cout << x << " is not a prime number" <<endl;
        return;
    }

    for(int i = 0;  i * i <= x; i++){
        if(x%i==0 && i!=1){
            cout<<x<<" is not a prime number"<<endl;
            return;
        }
    }

    cout<<x<<" is a prime number"<<endl;
    return;
}

int main(){
    check_prime(36);
    check_prime(100);
    check_prime(7);
    check_prime(11);
}