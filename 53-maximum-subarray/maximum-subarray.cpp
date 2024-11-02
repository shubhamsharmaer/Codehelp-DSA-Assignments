class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0];
        int maxSum = nums[0];

        // check for max sum
        for(int i = 1; i < nums.size(); i++){
            cur = max(nums[i], cur + nums[i]);
            maxSum = max(cur, maxSum);
        }
        return maxSum;
    }
};