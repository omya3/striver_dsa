#include<iostream>

using namespace std;

int main(){
    int age;
    cout<< "Please enter your age"<<endl;
    cin>>age;
    if(age>=18){
        cout<<"Hey there your age is "<<age<<" which is greater than or equal to 18 so u r n adult"<<endl;
    }
    else{
        cout<<"Hey there your age is "<<age<<" ehich is less than 18 so u r not n adult"<<endl;
    }
    return 0;
}