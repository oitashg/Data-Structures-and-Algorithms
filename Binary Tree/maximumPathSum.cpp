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
    //---------------------------------------------------------

    int maxSum(TreeNode* node, int& sum){
        if(node == NULL) return 0;

        //if -ve sum returns then make it 0 as -ve value will lower the sum
        int leftSum = max(0, maxSum(node->left, sum));
        int rightSum = max(0, maxSum(node->right, sum));
        sum = max(sum, node->val + leftSum + rightSum);
        
        return (node->val + max(leftSum, rightSum));
    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        maxSum(root, sum);
        return sum;
    }

    //----------------------------------------------------------
};