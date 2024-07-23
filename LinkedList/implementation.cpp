#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

int lenghtofLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == val) return 1;
        temp = temp->next;
    }

    return 0;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<endl;
}

int main(){
    vector<int> v = {5,3,4,6,7};
    Node* head = convertArr2LL(v);
    cout<<lenghtofLL(head)<<endl;
    cout<<"Present or not ->" <<checkIfPresent(head, 7);
    return 0;
}