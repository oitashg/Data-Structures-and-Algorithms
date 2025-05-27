#include<iostream>
#include<queue>
using namespace std;

//Compartor class to make a minimum heap
// We can use a custom comparator to define the order of elements in the priority queue.
class Compare{
public:
    //opeartor overloading for the comparator
    // This function will return true if the first argument is less than the second,
    // which means the first argument will have higher priority in the min-heap.
    bool operator()(int a, int b){
        return a<b;
    }
};

//--------------------T.C. of push() - O(logn)------------------
//--------------------T.C. of pop() - O(logn)-------------------
//--------------------T.C. of top() - O(1)----------------------

void explainStack(){
    //--------------Maximum heap----------------------------

    priority_queue<int> pq;

    pq.push(1);        //{1}
    pq.push(4);        //{4,1}
    pq.emplace(3);     //{4,3,1}

    pq.emplace(3,5);   //{{3,5}} Pair can be added like this 
    pq.emplace(6,7);   //{{3,5}, {6,7}}  

    cout<<pq.top();    //4

    pq.pop();          //{3,1}

    cout<<pq.top();    //3

    queue<int>pq1, pq2;
    pq1.swap(pq2); //priority_queue elements will be swapped

    //--------------Minimum heap----------------------------

    // We can customise the priority queue to behave like a minimum heap by using a comparator.
    // Here, we use greater<int> to make it a min-heap.
    priority_queue<int, vector<int>, greater<int>> pq;

    priority_queue<int, vector<int>, Compare> pqNew;

    pq.push(1);        //{1}
    pq.push(4);        //{1,4}
    pq.emplace(3);     //{1,3,4}

    cout<<pq.top();    //1

    pq.pop();          //{3,4}

    cout<<pq.top();    //3

    queue<int>pq1, pq2;
    pq1.swap(pq2); //priority_queue elements will be swapped
}