#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev); //prev becomes the back
        prev->next = temp;
        prev = temp;
    }

    return head;
}

Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;

    return newHead;
}

Node* insertBeforeTail(Node* head, int val){
    if(head->next == NULL){
        //single node present...so it's the tail as well as head...so insert before head
        return insertBeforeHead(head, val);
    }

    Node* tail = head;
    while(tail->next != NULL)
        tail = tail->next;
    
    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;

    return head;
}

Node* insertBeforeKthElement(Node* head, int val, int k){
    if(k == 1){
        //before head
        return insertBeforeHead(head, val);
    }

    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;

    return head;
}

//node will never be head, otherwise head will change
void insertBeforeNode(Node* temp, int val){
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
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
    Node* head = convertArr2DLL(v);
    head = insertBeforeHead(head, 12);
    head = insertBeforeTail(head, 16);
    head = insertBeforeKthElement(head, 17, 3);
    insertBeforeNode(head->next, 18);
    print(head);
    return 0;
}