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
    int maxDepth(TreeNode* root) {
        // base case
        if(root == NULL){
            return 0;
        }

        // left tree
        int leftDepth = maxDepth(root -> left);
        int rightDepth = maxDepth(root -> right);

        int ans = max(leftDepth, rightDepth);
        return ans + 1;

    }
};