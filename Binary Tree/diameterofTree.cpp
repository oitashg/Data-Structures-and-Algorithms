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
    //-----------------TC-O(N) and SC-O(N)----------------------------------

    int maxDepth(TreeNode* node, int& diameter) { //diameter passed as reference
        if(node == NULL) return 0;

        int lh = maxDepth(node->left, diameter);
        int rh = maxDepth(node->right, diameter);

        diameter = max(diameter, lh+rh);
        return (1 + max(lh,rh));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        maxDepth(root, diameter);

        return diameter;
    }

    //----------------------------------------------------
};