#include<iostream>

using namespace std;

int count(int n){
    int digits = 0;
    while (n>0)
    {
        n = n/10;
        digits++;
    }
    return digits;

}

double count_log_logic(double n){
    double digits = (int)(log10(n)+1);
    return digits;
}




int main(){
    double n, digits;
    cout<<" Please enter a number "<<endl;
    cin>>n;
    digits = count_log_logic(n);
    cout<<" There are "<<digits<<" digits in the number you entered"<<endl;

}