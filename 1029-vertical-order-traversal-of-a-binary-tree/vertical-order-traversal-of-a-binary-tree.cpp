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

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans; // define ans str
        queue<pair<TreeNode*, pair<int,int>>>q; // DS: Node, (row, col)
        map<int, map<int, multiset<int>>>mp; // DS: col -> <row, [x,y,z,.....]>

        q.push({root, {0,0}});
        while(!q.empty()) {
            auto front = q.front(); q.pop();
            TreeNode* &node = front.first; // Node
            auto cordinate = front.second; // cordinate --> (row, col) from above queue
            int& row = cordinate.first; // row
            int& col = cordinate.second; // col

            mp[col][row].insert(node->val); // push into map
            // check if root->left || right
            if(node->left)
                q.push({node->left, {row+1, col-1}});
            if(node->right)
                q.push({node->right, {row+1, col+1}});
        }

        // store the ans
        for(auto it:mp){ // outer map
            auto& colMap = it.second; // 
            vector<int> vLine; // to go rowise
            for(auto &colMapIt:colMap) {
                auto& mset = colMapIt.second;
                vLine.insert(vLine.end(), mset.begin(), mset.end());
            }
            ans.push_back(vLine);
        }
        return ans;
    }
};