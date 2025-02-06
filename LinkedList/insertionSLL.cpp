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

Node* insertHead(Node* head, int val){
    return new Node(val, head);
}

Node* insertTail(Node* head, int val){
    if(head == NULL){
        //no tail node so next will point to null always
        return new Node(val);
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node* insertKthPosition(Node* head, int val, int k){
    if(head == NULL){
        if(k==1){
            //similar to insert head
            return new Node(val);
        }
        else{
            //invalid k
            return head;
        }
    }

    if(k==1){
        //next will be head
        return new Node(val, head);
    }

    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;

        if(cnt == (k-1)){
            //temp->next becomes the next of newNode
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}

Node* insertBeforeElement(Node* head, int val, int el){
    if(head == NULL){
        return NULL;
    }

    if(head->data == el){
        //next will be head
        return new Node(val, head);
    }

    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->data == el){
            //temp->next becomes the next of newNode
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }
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
    vector<int> v = {5,3,4,6,7};
    Node* head = convertArr2LL(v);
    head = insertHead(head, 12);
    head = insertTail(head, 13);
    head = insertKthPosition(head, 14, 3);
    head = insertBeforeElement(head, 14, 6);
    print(head);
    return 0;
}