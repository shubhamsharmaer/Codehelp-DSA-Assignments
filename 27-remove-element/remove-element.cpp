class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // use std::remove to remove val from begin() -> end()
        // then nums will look like this -> [0,1,3,0,4,?,?,?]
        // ? -> garbage value
        // to erase this garbage value from nums in place -> nums.erase(it, nums.end())
        // return size()
        auto it = std:: remove(nums.begin(), nums.end(), val);
        nums.erase(it, nums.end());
        return nums.size();
    }
};