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
    //------------------------------------------------------------------

    bool f(TreeNode* node, long long minVal, long long maxVal){
        if(node == NULL) return true;
        if(node->val <= minVal || node->val >= maxVal) return false;

        return f(node->left, minVal, node->val) && f(node->right, node->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return f(root, -1e18, 1e18);
    }

    //---------------------------------------------------------------------
};