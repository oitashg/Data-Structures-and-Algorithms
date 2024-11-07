#include<iostream>
#include<vector>
using namespace std;

void explainVector(){
    vector<int> v;

    v.push_back(3);
    v.emplace_back(3);

    vector<pair<int,int>> vec;

    vec.push_back({1,2});
    vec.emplace_back(1,2);

    cout<<v.back(); //prints the last element of the vector
    cout<<v[0];     //prints element at index 0
    cout<<v.at(0);  //prints element at index 0

    //iterate the vector
    for(auto it: v) cout<<it<<" ";
    for(auto it = v.begin(); it != v.end(); it++) cout<<(*it)<<" ";
    
    //iterate the vector in reverse order
    for(auto it = v.rbegin(); it != v.rend(); it++) cout<<(*it)<<" ";

    //Insert function
    vector<int> v(2,100);           //{100,100}
    v.insert(v.begin(), 300);       //{300,100,100}  
    v.insert(v.begin()+1, 2, 10);   //{300,10,10,100,100} 

    vector<int> copy(2,50);         //{50,50}
    v.insert(v.begin(), copy.begin(), copy.end());   //{50,50,300,10,10,100,100}

    //{10,20}
    v.pop_back();   //{10}   

    cout<<v.empty();  //checks if vector is empty or not
}