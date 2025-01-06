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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int leftH = height(root->left);
        int rightH = height(root->right);
        int height = max(leftH, rightH);

        return height + 1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        // base case
        if(root == NULL){
            return 0;
        }

        int leftH = diameterOfBinaryTree(root -> left);
        int rightH = diameterOfBinaryTree(root -> right);
        int bothH = height(root->left) + height(root->right);

        int ans = max( bothH, max(leftH, rightH));
        return ans;
    }
};