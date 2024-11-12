class Solution {
public:
    vector<int> findprefix(vector<int>& nums){
        int n = nums.size();
        vector<int> prefixsum(n, 0);
        for(int i = 1; i < nums.size(); i++){
            prefixsum[i] += prefixsum[i - 1] + nums[i - 1]; 
        }
        return prefixsum;
    }

    vector<int> findsuffix(vector<int>& nums){
        int n = nums.size();
        vector<int> suffixsum(n, 0);
        for(int i = n - 2; i >= 0; i--){
            suffixsum[i] += suffixsum[i + 1] + nums[i + 1];
        }
        return suffixsum;
    }
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftsum;
        vector<int> rightsum;        
        int n = nums.size();
        
        leftsum = findprefix(nums);
        rightsum = findsuffix(nums);
        vector<int> ans;

        for(int i = 0; i < n; i++){
            // cout<<leftsum[i]<<" ";
            // cout<<rightsum[i]<<" ";
            int diff = abs(leftsum[i] - rightsum[i]);
            ans.push_back(diff);
        }
        return ans;
    }
};