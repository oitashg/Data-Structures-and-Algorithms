#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Comparator function
//First ascending wrt second element
//if both are same, then descending wrt to first element

bool comp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second < p2.second) return true;

    else if (p1.second == p2.second){
        if(p1.first > p2.first) return true;
        else return false;
    }

    else return false;
}

void explainAlgorithm(){
    vector<int> v;
    int a[] = {2,5};
    int n;

    //------------------------Sorting-----------------------------------

    //sorting in ascending order
    sort(a, a+n);
    sort(a+2, a+4);    //sort a part of array
    sort(v.begin(), v.end());

    //sorting in descending order(grater<int> is a inbuilt comparator function)
    sort(a, a+n, greater<int>());
    sort(v.begin(), v.end(), greater<int>());

    //We can sort an array or vector in any way using our own comparator function.
    //comparator function is always a boolean function
    pair<int,int> a[] = {{1,2}, {2,1}, {4,1}};
    sort(a, a+n, comp);  //{{4,1}, {2,1}, {1,2}}

    //---------------__builtin_popcount() counts the number of set bits present in an integer----------------------------

    int num = 7;
    int cnt = __builtin_popcount(num);

    long long num = 2345678876543;
    int cnt = __builtin_popcountll(num);   //for long long

    //------------------------------Permutations--------------------------------

    string s = "123";
    sort(s.begin(), s.end());   //sort it so that u can get all the permutations

    do{
        cout<<s<<endl;
    }
    while(next_permutation(s.begin(), s.end()));  //print the next permutations

    //--------------------------------------------------------------------------

    int maxi = *max_element(a, a+n);  //prints max element from an array or vector
    int maxi = *min_element(a, a+n);  //prints min element from an array or vector
}