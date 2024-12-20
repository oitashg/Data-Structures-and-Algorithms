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
    //-------------------------------------------------

    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        //condition for not being a balanced tree
        if(lh == -1 || rh == -1) return -1;
        if(abs(lh-rh) > 1) return -1;

        return (1 + max(lh,rh));
    }

    bool isBalanced(TreeNode* root) {
        int ans = maxDepth(root);

        if(ans == -1) return false;
        else return true;
    }

    //-------------------------------------------------
};