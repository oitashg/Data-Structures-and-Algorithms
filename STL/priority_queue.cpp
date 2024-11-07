#include<iostream>
#include<queue>
using namespace std;

//--------------------T.C. of push() - O(logn)------------------
//--------------------T.C. of pop() - O(logn)-------------------
//--------------------T.C. of top() - O(1)----------------------

void explainStack(){
    //--------------Maximum heap----------------------------

    priority_queue<int> pq;

    pq.push(1);        //{1}
    pq.push(4);        //{4,1}
    pq.emplace(3);     //{4,3,1}

    cout<<pq.top();    //4

    pq.pop();          //{3,1}

    cout<<pq.top();    //3

    queue<int>pq1, pq2;
    pq1.swap(pq2); //priority_queue elements will be swapped

    //--------------Minimum heap----------------------------

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(1);        //{1}
    pq.push(4);        //{1,4}
    pq.emplace(3);     //{1,3,4}

    cout<<pq.top();    //1

    pq.pop();          //{3,4}

    cout<<pq.top();    //3

    queue<int>pq1, pq2;
    pq1.swap(pq2); //priority_queue elements will be swapped
}