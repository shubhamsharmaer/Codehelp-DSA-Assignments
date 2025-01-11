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
    bool solve(TreeNode* root, int targetSum, int sum) {
        // base case
        if(root == NULL){
            return false;
        }
        // take sum
        sum += root->val;
        if(root->left == NULL && root->right == NULL) {
            // check sum
            if(sum == targetSum) {
                return true;
            }
            else {
                return false;
            }
        }

        // take left ans
        bool leftSum = solve(root->left, targetSum, sum);
        bool rightSum = solve(root->right, targetSum, sum);
        return leftSum||rightSum;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // take a sum var
        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;
    }
};