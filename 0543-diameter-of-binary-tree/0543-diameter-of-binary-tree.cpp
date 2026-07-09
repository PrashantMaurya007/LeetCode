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
    int maxDiameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        getHeight(root);
        return maxDiameter;
    }
private:
    int getHeight(TreeNode* node){
        if(!node){
            return 0;
        }
        int leftH = getHeight(node->left);
        int rightH = getHeight(node->right);

        maxDiameter = max(maxDiameter,leftH+rightH);

        return 1+max(leftH,rightH);

    }
};