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
        // check null
        if(root == NULL){
            return 0;
        }

        int leftH = height(root->left);
        int rightH = height(root->right);

        return max(leftH, rightH) + 1;
    }
    bool isBalanced(TreeNode* root) {
        // check null
        if(root == NULL){
            return true;
        }
        // find the hegiht
        int LH = height(root->left);
        int RH = height(root->right);

        // if(abs(LH - RH) <= 1) return true;
        int diff = abs(LH - RH);
        bool currNode = (diff <= 1);

        // recursive call for left ans right
        bool LeftSubTree = isBalanced(root -> left);
        bool RightSubTree = isBalanced(root -> right);

        if((LeftSubTree && RightSubTree) && currNode) {
            return true;
        } 


        return false;

    }
};