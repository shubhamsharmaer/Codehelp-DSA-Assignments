class Solution {
public:
    // take one pointers curr = 1
    // start a for(next < nums.size())
    //          -> if([curr] != [next]) then curr+, [curr] = [next]
    // return curr + 1
    int removeDuplicates(vector<int>& nums) {
        int cur = 1;
        if(nums.size() <= 2) return nums.size();
        for(int next = 2; next < nums.size(); next++){
            if(nums[next] != nums[cur-1]){
                // move curr
                cur++;
                // update cur
                nums[cur] = nums[next];
            }
        } 
        return cur + 1;
    }
};