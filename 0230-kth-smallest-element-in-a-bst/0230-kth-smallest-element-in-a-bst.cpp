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
public: vector<int> inOrder(TreeNode* root, vector<int>& arr){
    if(!root){
        return arr;
    }
    inOrder(root->left,arr);
    arr.push_back(root->val);
    inOrder(root->right, arr);
    return arr;
}
public:
    int kthSmallest(TreeNode* root, int k) {
       vector<int> nums;
        inOrder(root, nums);           
        return nums[k - 1];
    }
};