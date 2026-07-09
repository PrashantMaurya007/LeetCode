/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxSum= INT_MIN;
public: int maxGain(TreeNode* node){
    if(!node){
        return 0;
    }

    int leftG= max(maxGain(node->left),0);
    int rightG = max(maxGain(node->right),0);

    int priceNewPath = node->val+ leftG +rightG;

    maxSum = max(maxSum, priceNewPath);
    return node->val+max(leftG, rightG);
}
public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};