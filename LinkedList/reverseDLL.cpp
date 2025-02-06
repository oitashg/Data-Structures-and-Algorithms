#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next,*back;
    Node()
    {
        this->data = 0;
        next = NULL;
        back= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->back = NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->back= prev;
    }
};

//The intuition behind this is swap(a,b)
//temp = a;
//a = b;
//b = temp;

//similarly here swapping the links

Node* reverseDLL(Node* head)
{   
    if(head == NULL || head->next == NULL) return head;

    Node* prev = NULL;
    Node* current = head;

    while(current != NULL){
        prev = current->back;
        current->back = current->next;
        current->next = prev;
        current = current->back;
    }  

    return prev->back;
}

