#include <iostream>
#include <vector>
#include <queue>
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
    //---------------Left Root Right----------------------------

    void f(TreeNode* node, vector<int>& ans){
        if(node == NULL) return;

        f(node->left, ans);
        ans.push_back(node->val);
        f(node->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        f(root, ans);

        return ans;
    }

    //-------------------------------------------------------
};