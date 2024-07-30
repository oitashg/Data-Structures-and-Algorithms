#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


class Solution {
public:
    //--------------------------------------------------------------

    bool isLeaf(Node* root){
        if(root->left == NULL && root->right == NULL) return true;
        else return false;
    }
    
    void addLeftBoundary(Node* root, vector<int>& ans){
        Node* cur = root->left;
        
        while(cur != NULL){
            if(!isLeaf(cur)) ans.push_back(cur->data);
            if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }
    
    void addLeaves(Node* root, vector<int>& ans){
        //preorder traversal
        if(root == NULL) return;
        
        if(isLeaf(root)) ans.push_back(root->data);
        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }
    
    void addRightBoundary(Node* root, vector<int>& ans){
        Node* cur = root->right;
        stack<int> st;
        
        while(cur != NULL){
            if(!isLeaf(cur)) st.push(cur->data);
            if(cur->right) cur = cur->right;
            else cur = cur->left;
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;
        
        if(!isLeaf(root)) ans.push_back(root->data);
        
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);
        
        return ans;
    }

    //--------------------------------------------------------------
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}