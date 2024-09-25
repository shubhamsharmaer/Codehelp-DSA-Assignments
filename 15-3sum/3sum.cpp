class Solution {
public:
    // Uing two pointer approch Fixing x and find y + z == -x
    // take a vec vec ans
    // loop for nums ---> take left, right
    //               ---> skip duplicate if i > 0 && [i] == [i+1] continue;
    //               while left < right --> take sum = [left] + [right]
    //                if(sum == -nums[i]) then 
    //                  push in ans({[i], [left], [right]})
    //                    skip duplicates and move further check below
    //                else if sum < -nums[i] then left++; else right--;
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for(int i = 0; i < nums.size(); i++){
            // skip duplicate values
            if(i > 0 && nums[i] == nums[i-1]) continue;
            // int tar = nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum == -nums[i]){
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // move both pointer and skip  duplicates
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1] ) right--;
                    left++;
                    right--;
                }
                else if(sum < -nums[i]){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return ans;
    }
};