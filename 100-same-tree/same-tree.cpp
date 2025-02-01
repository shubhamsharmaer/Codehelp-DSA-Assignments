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
    bool postT(TreeNode* root1, TreeNode* root2) {
        // NLR
        if(!root1 && !root2) return true;
        if(root1 && root2) {
            return (root1->val == root2->val) // checking root val of both
                && 
                postT(root1 -> left, root2->left)
                && 
                postT(root1 -> right, root2->right);
        }
        // if(root1 -> val == root2 -> val) return true;

        return false; // this is last case left where any one tree is null
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return postT(p,q);
    }
};