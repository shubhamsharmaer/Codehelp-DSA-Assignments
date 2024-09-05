class Solution {
public:
    void helper(vector<int>& nums, int cur, int next){
        // base case
        if(next == nums.size()){
            return;
        }
        
        // case sol
        if(nums[cur] == nums[next]){
          nums.erase(nums.begin() + next);
          helper(nums, cur, next);
        }
        else{
          helper(nums, cur+1, next+1);
        }
    }
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        helper(nums, 0, 1);
        return nums.size();
    }
};