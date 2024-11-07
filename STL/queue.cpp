#include<iostream>
#include<queue>
using namespace std;

void explainStack(){
    queue<int> q;

    q.push(1);        //{1}
    q.push(2);        //{1,2}
    q.emplace(3);     //{1,2,3}

    cout<<q.back();   //3
    cout<<q.front();  //1

    q.pop();          //{2,3}

    cout<<q.front();  //2

    queue<int>q1, q2;
    q1.swap(q2); //queue elements will be swapped
}