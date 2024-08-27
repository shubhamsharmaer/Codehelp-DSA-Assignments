class Solution {
public:
    // take n size var
    // take an ans vector of same n size
    // start loop
    //      take a new index -> (i+k) % n
    //      ans[newindex] = nums[i]
    // nums = ans
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        // loop 
        for(int i = 0; i < n; i++){
            int newindex = (i+k) % n;
            ans[newindex] = nums[i];
        }
        nums = ans;
    }
};