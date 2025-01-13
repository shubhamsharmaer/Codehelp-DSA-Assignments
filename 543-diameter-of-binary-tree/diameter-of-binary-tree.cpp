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
    int maxHeight(TreeNode* root) {
        // base case
        if(root == NULL) {
            return 0;
        }

        int leftH = maxHeight(root->left);
        int rightH = maxHeight(root->right);
        int ans = max(leftH, rightH) + 1;
        return ans; 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // check for root null
        if(root == NULL) {
            return 0;
        }
        int leftH = diameterOfBinaryTree(root->left);
        int rightH = diameterOfBinaryTree(root->right);
        int bothH = maxHeight(root->left) + maxHeight(root->right);
        int ans = max(bothH, max(leftH, rightH));
        return ans;
        
    }
};