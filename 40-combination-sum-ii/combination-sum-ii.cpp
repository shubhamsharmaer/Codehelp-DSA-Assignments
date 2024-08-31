class Solution {
public:
    // all logic same as combination sum - I
    // Just REMBER THESE -> sort candidates
    //                   -> recursive call with (i + 1)
    //                   -> inside loop check if i > index && [i] == [i-1] then continue;
    void combinationSum2Helper(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& v, int target, int index){
        // base condition
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(target < 0){
            return;
        }

        // loop 
        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            v.push_back(candidates[i]);
            //recusive call
            combinationSum2Helper(candidates, ans, v, target-candidates[i], i+1);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        combinationSum2Helper(candidates, ans, v, target, 0);
        return ans;
    }
};