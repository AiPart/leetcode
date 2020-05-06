/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // bool isValidBST(TreeNode* root) { /* 原函数声明 */
    bool isValidBST(TreeNode* root, TreeNode* left=NULL, TreeNode* right=NULL) {
        if (!root) {
            return true;
        }
        if (left && left->val >= root->val) {
            return false;
        }
        if (right && right->val <= root->val) {
            return false;
        }
        return isValidBST(root->left, left, root) 
                       && isValidBST(root->right, root, right);
    }
};
