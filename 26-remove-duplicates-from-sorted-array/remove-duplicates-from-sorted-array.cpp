class Solution {
public:
    // take two pointers curr, next
    // start a while(next < nums.size())
    //          -> if([curr] == [next]) then nums.erase(begin()+next)
    //          -> else curr++, next++
    // return nums.size()
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        int curr = 0;
        int next = 1;
        // helper(nums, 0, 1);
        while(next < nums.size()){
            // for(int i = 0; i < nums.size(); i++){
                if(nums[curr] == nums[next]){
                    nums.erase(nums.begin() + next);
                }
                else{
                    curr++,next++;
                }
        }
        return nums.size();
    }
};