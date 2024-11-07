#include<iostream>
#include<list>
using namespace std;

void explainList(){
    list<int> ls;

    ls.push_back(5);      //{5}
    ls.emplace_back(6);   //{5,6}

    ls.push_front(4);     //{4,5,6}
    ls.emplace_front(3);   //{3,4,5,6}

    //rest functions are same as vector
    //begin, end, rbegin, rend, clear, insert, size, swap
}