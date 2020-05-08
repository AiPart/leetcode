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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) {
            return true;
        }
        if (!s || !t) {
            return false;
        }

        return isSametree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool isSametree(TreeNode* s, TreeNode* t) {
        if (!s && !t) {
            return true;
        }
        if (!s || !t) {
            return false;
        }
        return (s->val == t->val) && isSametree(s->left, t->left) && isSametree(s->right, t->right);
    }
};
