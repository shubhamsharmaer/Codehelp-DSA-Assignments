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
    // optimized approch
    int Dia = 0;
    int maxHeight(TreeNode* root) {
        // base case
        if(root == NULL) {
            return 0;
        }
        int lh = maxHeight(root->left);
        int rh = maxHeight(root->right);

        // use currNode
        int currD = lh + rh;
        Dia = max(Dia, currD); 
        return max(lh, rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // check for root null
        if(root == NULL) {
            return 0;
        }

        maxHeight(root);
        return Dia;

        // int leftH = diameterOfBinaryTree(root->left);
        // int rightH = diameterOfBinaryTree(root->right);
        // int bothH = maxHeight(root->left) + maxHeight(root->right);
        // int ans = max(bothH, max(leftH, rightH));
        // return ans;
        
    }
};