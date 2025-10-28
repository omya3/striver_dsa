#include<iostream>
#include<string>

using namespace std;

void print_name(int count, string name){
    if(count < 5){
        cout<<name<<endl;
        count++;
        print_name(count, name);
    }
    return;
}

int main(){
    int count = 0;
    string name;
    cout<<"Please enter the name"<<endl;
    cin>>name;
    cout<<"//////////"<<endl;
    print_name(count, name);
}