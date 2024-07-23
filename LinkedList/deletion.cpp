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

Node* removeHead(Node* head){
    //must to be written everywhere
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* removeKthElement(Node* head, int k){
    if(head == NULL) return head;

    //k = 1..i.e remove head
    if(k == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

Node* removeElement(Node* head, int val){
    if(head == NULL) return head;

    //if value = head->data...remove head
    if(head->data == val){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == val){
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<endl;
}

int main(){
    vector<int> v = {5,3,4,6,7,8,3,75,7,3,98};
    Node* head = convertArr2LL(v);
    head = removeHead(head);
    head = removeTail(head);
    head = removeKthElement(head, 3);
    head = removeElement(head, 6);
    print(head);
    return 0;
}