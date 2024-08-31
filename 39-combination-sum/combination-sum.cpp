class Solution {
public:
    // take an ans vector<vector> to return 
    // take v vector to store curr element
    // In combinationSumHelper -> base case: 
    //                              if target == 0 -> ans.push(v), return 
    //                              if target < 0 -> return
    //                          -> loop (i = index ; i < candidates.size())
    //                              push [i] in v
    //                              recursive call with target-candidates[i], i
    //                              v.pop_back()
    void combinationSumHelper(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& v, int target, int index) {
        // base case
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(target < 0){
            return;
        }

        // loop 
        for(int i = index; i < candidates.size(); i++){
            v.push_back(candidates[i]);
            combinationSumHelper(candidates, ans, v, target-candidates[i], i);
            v.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        combinationSumHelper(candidates, ans, v, target, 0);
        return ans;
    }
};