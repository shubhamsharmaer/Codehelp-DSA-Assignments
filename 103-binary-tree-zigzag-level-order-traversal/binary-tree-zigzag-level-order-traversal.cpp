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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        // check for null
        if(!root) return ans;
        queue<TreeNode*> q; // for storing node->val

        q.push(root);
        bool LTR = true; // flag to change order left <-> right

        while(!q.empty()) {
            int len = q.size(); // length for queue
            vector<int> OneLevel(len); // sub arr for ans[[...], ...] with len
            for(int i = 0; i < len; i++) {
               TreeNode* node = q.front(); q.pop();
               int index = LTR ? i : len - i - 1;
               OneLevel[index] = node->val;

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            LTR = !LTR;
            ans.push_back(OneLevel);
        }
        return ans;
    }
};