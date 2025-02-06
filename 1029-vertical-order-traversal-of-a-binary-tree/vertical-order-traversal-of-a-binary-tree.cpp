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
            vector<vector<int>> ans;
            // store node --> {row, col}
            queue<pair<TreeNode*, pair<int, int>>> q;
            // store col --> < row, node val>
            map<int, map<int, multiset<int>>> mp;

            // push into queue
            q.push({root, {0,0}});
            // traverse row level
            while(!q.empty()) {
                // take values
                auto front = q.front(); q.pop(); // taking node
                TreeNode* &node = front.first;
                auto cordinate = front.second;
                int &row = cordinate.first;
                int &col = cordinate.second;
                
                mp[col][row].insert(node->val); // push into map node->val 
                
                if(node->left)
                     q.push({node->left, {row+1, col-1}});
                if(node->right)
                     q.push({node->right, {row+1, col+1}});
            }

            // storing into ans
            for(auto it:mp) {
                auto &colToRow = it.second; // <row, {x, y}>
                vector<int> vLine;
                for(auto rowToPair: colToRow) {
                    auto &mset = rowToPair.second; // {x,y}
                    vLine.insert(vLine.end(), mset.begin(), mset.end());
                }
                ans.push_back(vLine);
            }
            return ans;

    }
};