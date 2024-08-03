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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        int cur = root->val;

        if(p->val > cur && q->val > cur)
            return lowestCommonAncestor(root->right, p, q);
            
        if(p->val < cur && q->val < cur)
            return lowestCommonAncestor(root->left, p, q);

        //when both condition fail means either splitting or anyone of them is root which is the lca
        return root;
    }
};