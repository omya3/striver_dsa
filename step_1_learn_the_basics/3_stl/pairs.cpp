// Pairs: a pair is part of utility in C++


#include<iostream>

using namespace std;

int main(){

    pair<int, int> p = {1,2};

    cout<<p.first<<" "<<p.second<<endl;

    pair<int, pair<int,int>> q= {3, {4, 5}};

    cout<<q.first<<endl;

    cout<<q.second.first<<" "<<q.second.second<<endl;

    return 0;
}