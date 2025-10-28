// is made upof double linked listt, insert
// operation is much cheaper here
#include <iostream>
#include <set>
#include <list>
#include <unordered_set>
#include <map>

using namespace std;


void explain_list(){

    list<int> ls;
    ls.push_back(2);
    ls.emplace_back(4);

    ls.push_front(5);
    ls.emplace_front(6);

    //rest functions are same as vector
    // begin, end, rbegin, end, clear, insert, size, swap
    return;
}

void explain_stack(){

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    st.emplace(5); // similar to push
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    cout<<st.empty()<<endl;
    return;

}

void explain_queue(){

    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(3);

    q.back()+=5;
    cout<<q.back()<<endl;
    q.pop(); // delete from front
    cout<<q.front()<<endl;

    return;
}

void explain_priority_q(){

    // Max heap
    priority_queue<int> pq;

    pq.push(5);
    pq.push(2);
    pq.push(20);
    pq.push(8);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;


    // Min heap
    priority_queue<int, vector<int>, greater<int>> pqr;
    pqr.push(5);
    pqr.push(2);
    pqr.push(8);
    pqr.emplace(10);

    cout<<pqr.top()<<endl;

    return;
}

void explain_set(){

    // everything happens in logarithmic time complexity
    // stores everything in sorted order and stores unique

    set<int> st;
    st.insert(1);
    st.emplace(2);
    st.insert(2);
    st.insert(4);
    st.insert(3);
    
    auto it = st.find(5); // since 5 is not found it will return iterator pointing to last element in set
    
    st.erase(5); // takes logarithmic time

    auto it1 = st.find(3);
    st.erase(it1);

    int cnt = st.count(2); // returns 1 if element is present in set
    cout<<cnt<<endl;

    return;
}

void explain_multiset(){
    // stores everything in sorted order
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(7);
    ms.insert(5);

    int cnt = ms.count(1);
    cout<<cnt<<endl;
    ms.erase(1); // erases all the 1's

    cnt = ms.count(1);
    cout<<cnt<<endl;

}

void explain_unordered_set(){
    // just stores unique elements
    // in all the operations  beat case time complexity is O(1) 
    // and in worst case complexity is O(n)

    unordered_set<int> st;

}

void explain_map(){
    // map stores unique keys in sorted order
    map<int, int> mpp;
    map<int, pair<int,int>> map2;
    map<pair<int,int>, int> map3;

    mpp[1]=2;
    mpp[1]=3;
    mpp.insert({2,3});
    mpp.insert({3,4});

    for(auto it: mpp){
        cout<<it.first<<": "<<it.second<<endl;
    }
    return;

}

void explain_multi_map(){
    // similar to map, only it can store multiple keys
    // only mp[key] cannot be used
}

void explain_unordered_map(){
    // similar to multi map, only it is not sorted
}


int main()
{
    // explain_queue();
    // explain_stack();
    // explain_queue();
    // explain_priority_q();
    // explain_set();
    // explain_multiset();
    // explain_unordered_set();
    explain_map();

    return 0;
}