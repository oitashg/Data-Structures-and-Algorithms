#include<iostream>
#include<stack>
using namespace std;

void explainStack(){
    stack<int> st;

    st.push(1);         //{1}
    st.push(2);         //{2,1}
    st.emplace(3);      //{3,2,1}

    cout<<st.top();     //3

    st.pop();           //{2,1}

    cout<<st.top();     //2
    cout<<st.size();    //2
    cout<<st.empty();   //false

    stack<int>st1, st2;
    st1.swap(st2); //stack elements will be swapped
}