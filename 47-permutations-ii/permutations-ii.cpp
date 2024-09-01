class Solution {
public:
    // To Find Uniques pairs
    //  use unordered_map of <int, bool>
    //  -> inside loop if(visited.find(nums[i]) != visited.end()) then continue
    //  -> visited[nums[i]] = true; 
    // Main Approach -> take ans vector<vector> 
    //               -> call helperfun()
    // Helper Logic -> Base condn 
    //                   if start == nums.size() then push nums in ans and return
    //              -> loop (start -> nums.size())
    //                  -> swap(i , start)  YHA MA GALTI KRUGA
    //                  -> recursive call with (i+1)
    //                  -> swap(i , start)  YHA MA GALTI KRUGA
                        
    
    void permuteUniqueHelper(vector<vector<int>>& ans, vector<int>& nums, int start){
        // base condn
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_map<int, bool>visited;
        // loop 
        for(int i = start; i < nums.size(); i++){
            if(visited.find(nums[i]) != visited.end()){
                continue;
            }
            visited[nums[i]] = true;
            swap(nums[i], nums[start]);
            //recursie call
            permuteUniqueHelper(ans, nums, start+1);
            swap(nums[i], nums[start]);
        }
    };
     
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        permuteUniqueHelper(ans, nums, 0);
        return ans;
    }
};