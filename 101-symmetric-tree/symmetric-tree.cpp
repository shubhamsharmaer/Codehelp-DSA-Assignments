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
    bool isSame(TreeNode* l, TreeNode* r) {
        if(!l && !r) return true;
        if(l && r) {
            return (l-> val == r->val)
            && isSame(l->left, r->right)
            && isSame(l->right, r->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        // check for nulk
        if(!root) return true;
        bool same = isSame(root->left, root->right);
        if(same) return true;

        return false;
    }
};