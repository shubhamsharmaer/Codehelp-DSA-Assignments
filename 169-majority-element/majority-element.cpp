class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort
        sort(nums.begin(), nums.end());
        // return mid element
        return nums[nums.size() / 2];
    }
};