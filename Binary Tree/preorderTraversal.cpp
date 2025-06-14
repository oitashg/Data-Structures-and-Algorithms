#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //---------------Root Left Right------------------------------

    void f(TreeNode* node, vector<int>& ans){
        if(node == NULL) return;

        ans.push_back(node->val);
        f(node->left, ans);
        f(node->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        f(root, ans);

        return ans;
    }

    //---------------------------------------------------------------
};