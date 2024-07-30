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
    //------------Apply any tree traversal. If same then identical tree----------

    void f(TreeNode* node, vector<int>& ans){
        if(node == NULL){
            ans.push_back(1e9);
            return;
        }

        ans.push_back(node->val);
        f(node->left, ans);
        f(node->right, ans);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;

        vector<int> ans1;
        vector<int> ans2;

        f(p, ans1);
        f(q, ans2);

        if(ans1 == ans2) return true;
        return false;
    }

    //----------------------------------------------------------------
};