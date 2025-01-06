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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root == NULL) return NULL;
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;

        // find left node and right node
        TreeNode* leftN = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightN = lowestCommonAncestor(root->right, p, q);

        // now 4 cases left
            // L --> !N, R --> !N
            // L --> N, R --> !N
            // L --> !N, R --> N
            // L --> N, R --> N
        if(leftN != NULL && rightN != NULL) {
            return root;
        }
        if(leftN == NULL && rightN != NULL) {
            return rightN;
        }
        if(leftN != NULL && rightN == NULL) {
            return leftN;
        }
        // if(leftN == NULL && rightN == NULL) {
            return NULL;
        // }

    }
};