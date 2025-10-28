// Vectors: It is allocated memory at runtime and
// you do not need to declare size like yo do in array.
// It is dynamic in nature.
#include <iostream>
using namespace std;


int main()
{

    vector<int> v;

    v.push_back(1);
    v.emplace_back(2); // works faster than push_back.
    cout << v[0] << ", " << v[1] << endl;

    vector<pair<int, int>> v1;
    v1.push_back({1, 2});
    cout<< v1[0].first<<" "<<v1[0].second<<endl;

    v1.emplace_back(3, 4);
    cout<< v1[1].first<<" "<<v1[1].second<<endl;

    vector<int> v2(5, 100); // v2(size, initial_value) :)
    cout<<v2[0]<<", "<<v2[1]<<", "<<v2[2]<<", "<<v2[3]<<", "<<v2[4]<<endl;

    vector<int> v3(5); // v3(size) and it will be initialised 
    // randomly but still we can push back more elements
    cout<<v3[0]<<", "<<v3[1]<<", "<<v3[2]<<", "<<v3[3]<<", "<<v3[4]<<endl;

    vector<int>:: iterator it = v3.begin();
    cout<<*(it)<<endl;
    it++;
    cout<<*(it)<<endl;

    it = v3.end(); // WARNING: this will point to the memory location
    // just after the end of the array.

    vector<int>:: reverse_iterator itrev = v3.rend(); // reverse the array and then point to the location
    // just after the end of the array.
    cout<<*(itrev)<<endl;

    for(vector<int>:: iterator itlo = v2.begin(); itlo!= v2.end(); itlo++){
        cout<<*(itlo)<<" ";
    }

    cout<<endl;

    for(auto itlo = v2.begin(); itlo!= v2.end(); itlo++){ // use auto keyword to automatically assign vector operator.
        cout<<*(itlo)<<" ";
    }

    cout<<endl;

    for(auto itlo : v2){ // yet another way to iterate for each loop
        cout<<itlo<<" "; // see that we do not need to dereference here
    }

    cout<<endl;

    // DELETION IN AN VECTOR USING ERASE FUNCTION

    cout<<"AN EXAMPLE TRIAL VECTOR"<<endl;
    vector<int> trial = {1,2,3};

    for(auto it: trial){
        cout<<it<<" ";
    }

    cout<<endl;

    vector<int>:: iterator delit = trial.begin()+1;
    trial.erase(delit);
    cout<< "TRIAL VECTOR AFTER DELETION"<<endl;

    for(auto it: trial){
        cout<<it<<" ";
    }
    
    cout<<endl;

    trial.emplace_back(4);
    trial.emplace_back(5);
    trial.emplace_back(6);

    cout<<"TRIAL VECTOR AFTER INSERTION"<<endl;

    for(auto it: trial){
        cout<<it<<" ";
    }

    cout<<endl;

    delit = trial.begin()+1;
    trial.erase(delit, delit+2);
    cout<< "TRIAL VECTOR AFTER DELETION OF MULTIPLE ITEMS"<<endl;

    for(auto it: trial){
        cout<<it<<" ";
    }

    cout<<endl;

    vector <int> vnew = {1,2,3,4,5};

    for(auto it: vnew){
        cout<<it<<" ";
    }
    cout<<endl;

    vnew.insert(vnew.begin(), 200);
    for(auto it: vnew){
        cout<<it<<" ";
    }
    cout<<endl;


    vnew.insert(vnew.begin()+1, 2, 10);

    for(auto it: vnew){
        cout<<it<<" ";
    }
    cout<<endl;

    




    return 0;
}
