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
public:
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }

        int leftH = getHeight(root->left);
        int rightH = getHeight(root->right);

        if(abs(leftH -rightH) > 1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }

    private:
            int getHeight(TreeNode* node){
                if(node == nullptr){
                    return 0;

                }
                int leftH = getHeight(node->left);
                int rightH = getHeight(node->right);
                return max(leftH ,rightH)+1;
            

            }
};