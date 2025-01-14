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
    // taking global var
    bool isbal = true; // assuming every tree is balanced
    int height(TreeNode* root) {
        // base case
        if(!root) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        // check for false cond
        if(isbal && abs(lh - rh) > 1) {
            isbal = false;
        }

        int ans = max(lh, rh) + 1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
       height(root);
       return isbal;
       
       
       
       
        // take base case
        // if(!root) return true;
        
        // for one case
        // int lh = height(root->left);
        // int rh = height(root->right);
        // if(abs(lh - rh) <= 1) return true;
        // int diff = abs(lh - rh);
        // bool currNode = diff <= 1;

        // baki recurssion sambhalega
        // bool leftH = isBalanced(root->left);
        // bool rightH = isBalanced(root->right);
        
        // we have 3 things --> currNode res, leftH, rightH
        // if anyone got true then final ans --> true
        // use OR gate
        // if(currNode && (leftH && rightH)) return true;
        // else return false;
        

    }
};