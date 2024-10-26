class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // take two var
        int cur = nums[0];
        int maxSum = nums[0];

        // loop for calculating the subarray sum
        for(int i = 1; i < nums.size(); i++){
            cur = max(nums[i], cur + nums[i]);
            maxSum = max(maxSum, cur);
        }
        return maxSum;
    }
};