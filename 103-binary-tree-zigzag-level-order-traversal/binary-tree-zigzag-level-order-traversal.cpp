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
        // validate the null root
        if(!root) return ans;
        // make a queue
        queue<TreeNode*> q;
        
        bool LTR = true; // flag for toggle order
        // push root in queue
        q.push(root);

        while(!q.empty()) {
            // take lenth var
            int len = q.size();
            vector<int> OneLevel(len);

            for(int i = 0; i < len; i++) {
                // take a front of q
                TreeNode* node = q.front(); q.pop();
                int index = LTR ? i : len - i - 1;

                OneLevel[index] = node->val;

                // check for left and right
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);

            }
            // currLevel++;
            LTR = !LTR;
            ans.push_back(OneLevel);
        }   
        return ans;
    }
};