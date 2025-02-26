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
        // make a queue
        queue<TreeNode*> q;
        bool flag = true;
        // push node in queue
        q.push(root);
        // traverse queue
        while(!q.empty()) {
            int len = q.size();
            // take a vec
            vector<int> OneSubVec(len);
            // loop on queue
            for(int i = 0; i < len; i++){
                TreeNode* node = q.front(); q.pop();
                int index = flag ? i : len - i - 1;
                OneSubVec[index] = node->val;

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            flag = !flag;
            ans.push_back(OneSubVec);
        }
        return ans;
    }
};