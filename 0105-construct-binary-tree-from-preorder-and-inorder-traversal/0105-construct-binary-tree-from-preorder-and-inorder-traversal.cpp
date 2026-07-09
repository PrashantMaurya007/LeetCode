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
    int preorderIndex;
    unordered_map<int, int> inorderIndexMap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        inorderIndexMap.clear();
        
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i; 
        }
        return arraytoTree(preorder, 0, preorder.size() - 1);
    }
    
public:
    TreeNode* arraytoTree(vector<int>& preorder, int l, int r) {
        if (l > r) {
            return nullptr; 
        }
        
        int rootVal = preorder[preorderIndex];
        preorderIndex++;

        TreeNode* root = new TreeNode(rootVal);
        int rootInorderIdx = inorderIndexMap[rootVal];
        
       
        root->left = arraytoTree(preorder, l, rootInorderIdx - 1);
        root->right = arraytoTree(preorder, rootInorderIdx + 1, r);

        return root;
    }
};