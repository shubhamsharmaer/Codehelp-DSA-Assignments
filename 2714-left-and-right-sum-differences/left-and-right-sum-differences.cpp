class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        // calculating  total_sum
        int total_sum = 0;
        for(auto num : nums){
            total_sum += num;
        }

        // take 3 int --> prefixSum, suffixSum, total_sum
        // suffixSum = total_Sum - prefixSum - nums[i]
        int prefixSum = 0;
        int n = nums.size();
        vector<int> ans;
        // loop for finding ans vector
        for(int i = 0; i < n; i++){
            int suffixSum = total_sum - prefixSum - nums[i];
            int diff = abs(prefixSum - suffixSum);
            // int diff = abs(leftsum[i] - rightsum[i]);
            ans.push_back(diff);
            prefixSum += nums[i];
        }
        return ans;
    }
};