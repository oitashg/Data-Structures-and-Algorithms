#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

//----------------Maps store unique keys in sorted order---------------------
//---------------T.C. of every operation of map is O(logn)-------------------

void explainMap(){
    map<int,int> mp;
    map<int,pair<int,int>> mpp;
    map<pair<int,int>,int> mpp;

    mp[1] = 2;
    mp.emplace(3,1);   //(key, value)
    mp.insert({2,4});  //{key, value}

    //find function returns the iterator taht points to address
    auto it = mp.find(2);
    cout<<(*it).second;

    auto it = mpp.lower_bound(2);
    auto it = mpp.upper_bound(4);

    //erase, swap, size, empty are same as others
}

//----------------Multimaps store duplicate keys in sorted order-------------

void explainMultimap(){
    multimap<int, int> mp;

}

//----------------Unordered maps store unique keys in any order----------------------
//------------------T.C. of every operation of unordered_map is O(1)-----------------
//-----------------------In worst case it can be O(N)--------------------------------

void explainUnordered_map(){
    unordered_map<int,int> mp;
}

//----------------Unordered multimaps store duplicate keys in any order---------------

void explainUnordered_multimap(){
    unordered_multimap<int,int> mp;
}