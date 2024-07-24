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

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;

    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* tail = head;
    while(tail->next != NULL)
        tail = tail->next;

    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;

    return head;
}

Node* deleteKthElement(Node* head, int k){
    if(head == NULL) return NULL;

    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    //now we are standing on kth element i.e temp
    Node* prev = temp->back;
    Node* front = temp->next;;

    if(prev == NULL && front == NULL) return NULL;
    else if(prev == NULL){
        //removing head
        return deleteHead(head);
    }
    else if(front == NULL){
        //removing tail
        return deleteTail(head);
    }

    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;

    return head;
}

//can never remove head node, otherwise head will change
void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    //delete tail node
    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }

    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    delete temp;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<endl;
}

int main(){
    vector<int> v = {5,3,4,6,7,5,7,9,23,6};
    Node* head = convertArr2DLL(v);
    head = deleteHead(head);
    head = deleteTail(head);
    head = deleteKthElement(head, 2);
    deleteNode(head->next->next);
    print(head);
    return 0;
}