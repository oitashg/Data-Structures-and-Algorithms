#include <iostream>
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

class Solution
{
public:
    TreeNode *helper(TreeNode *node)
    {
        if (node == NULL)
            return NULL;

        if (node->left == NULL)
            return node->right;
        else if (node->right == NULL)
            return node->left;

        TreeNode *rightChild = node->right;
        TreeNode *lastRight = findLastRight(node->left);
        lastRight->right = rightChild;

        return node->left;
    }

    TreeNode *findLastRight(TreeNode *node)
    {
        if (node->right == NULL)
            return node;

        return findLastRight(node->right);
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;

        if (root->val == key)
            return helper(root);

        TreeNode *dummy = root;

        while (root != NULL)
        {
            if (root->val < key)
            {
                if (root->right != NULL && root->right->val == key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else
                    root = root->right;
            }
            else
            {
                if (root->left != NULL && root->left->val == key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else
                    root = root->left;
            }
        }

        return dummy;
    }
};