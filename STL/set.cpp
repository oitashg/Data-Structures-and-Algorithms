#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

//----------------Set arranges the elements in unique and sorted order------------
//-------------------T.C. of every operation in set is O(logn)--------------------

void explainSet(){
    set<int> st;

    st.insert(1);    //{1}
    st.insert(3);    //{1,3}
    st.insert(3);    //{1,3}
    st.insert(7);    //{1,3,7}
    st.emplace(4);   //{1,3,4,7}

    auto it = st.find(3);  //returns the iterator which points at 3 i.e. at address of 3

    auto it = st.find(6);  //if element is absent in set, then it returns st.end() i.e right after the last element

    st.erase(4);

    int cnt = st.count(1); //if exist then always 1 as set contain unique elemnet otherwise 0

    auto it = st.find(3);
    st.erase(it);

    //{1,2,3,4,5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); //after erase {1,4,5} [first, last) last excluded

    //lower_bound and upper_bound
    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);

    //iterate the set
    for(auto it = st.begin(); it != st.end(); it++) cout<<(*it);

    //iterate the set in reverse order
    for(auto it = st.rbegin(); it != st.rend(); it++) cout<<(*it);
}

void explainMutiSet(){
    //Everything is same as set
    //Only stores duplicate elements too
    //Not unique but sorted

    multiset<int> ms;

    ms.insert(1);   //{1}
    ms.insert(1);   //{1,1}
    ms.insert(1);   //{1,1,1}
    ms.insert(3);   //{1,1,1,3}
    ms.insert(2);   //{1,1,1,2,3}
    ms.insert(2);   //{1,1,1,2,2,3}

    ms.erase(1);    //all 1's are erased

    int cnt = ms.count(1);  //3

    ms.erase(ms.find(1)); //only one occurence of 1 is erased as here iterator is passed not element

    //rest all function same as set
}

//-------------------T.C. of every operation in unorderd_set is O(1)--------------------
//--------------------In worst case and very rarely T.C.can be O(n)---------------------

void explainUnordered_Set(){
    //Everything is same as set
    //Only stores unique elements
    //Unique but not sorted

    //lower_bound and upper_bound function does not works,
    //rest all functions are same
    //Better complexity 
    //than set in most cases, except some when collision happens

    unordered_set<int> st;

    st.insert(1);   //{1}
    st.insert(1);   //{1}   
    st.insert(7);   //{1,7}
    st.insert(6);   //{1,7,6}
    st.insert(3);   //{1,7,6,3}
}

//-----------------It stores duplicate elements in any order-------------------------

void explainUnordered_multiset(){
    unordered_multiset<int> st;

    st.insert(1);   //{1}
    st.insert(1);   //{1,1}
    st.insert(1);   //{1,1,1}
    st.insert(6);   //{1,1,1,6}
    st.insert(2);   //{1,1,1,6,2}
    st.insert(4);   //{1,1,1,6,2,4}
}