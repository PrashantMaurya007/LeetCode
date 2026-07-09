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
private:
    TreeNode* prev; // Tracks the previously visited node

public:
    bool isValidBST(TreeNode* root) {
        prev = nullptr; // Reset for each call
        return inOrder(root);
    }

private:
    bool inOrder(TreeNode* root) {
        // Base case: an empty tree/subtree is a valid BST
        if (!root) return true;

        // 1. Traverse the left subtree
        if (!inOrder(root->left)) {
            return false;
        }

        // 2. Process current node: must be strictly greater than the previous node
        if (prev != nullptr && root->val <= prev->val) {
            return false;
        }
        prev = root; // Update prev to the current node

        // 3. Traverse the right subtree
        return inOrder(root->right);
    }
};