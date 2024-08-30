class Solution {
public:
// take vars
    //         1 maxLeftBordersum, maxRightBordersum -> INT_MIN
    //         2 recursive call -> maxleftsum, maxrightsum
    //         3 leftbordersum, rightbordersum -> 0
    // loop for leftbordersum for(i = mid; i >= start; i--)
    //              leftbordersum += v[i]
    //              check if leftbordersum > maxLeftBordersum -> maxLeftBordersum = leftbordersum
    // same for rightbordersum for(i = mid+1; i <= end; i++)
    //              rightbordersum += v[i] 
    //              check if rightbordersum > maxRightBordersum -> maxRightBordersum = rightbordersum
    // take CrossBorderSum = maxRightBordersum + maxLightBordersum
    // return max(CrossBorderSum, max(maxleftsum, maxrightsum))
    int maxSubArrayHelper(vector<int>& v, int start, int end){
        int mid = start + ((end - start) / 2);
        //base case
        if(start == end) return v[start];

        int maxLeftBordersum = INT_MIN, maxRightBordersum = INT_MIN;

        // recursive call
        int maxleftsum = maxSubArrayHelper(v, start, mid);
        int maxrightsum = maxSubArrayHelper(v, mid+1, end);

        int maxleftbordersum = 0, maxrightbordersum = 0;
        // loop for leftsum
        for(int i = mid; i >= start; i--){
            maxleftbordersum += v[i];
            if(maxleftbordersum > maxLeftBordersum) maxLeftBordersum = maxleftbordersum; 
        }
        // loop for rightsum
        for(int i = mid+1; i <= end; i++){
            maxrightbordersum += v[i];
            if(maxrightbordersum > maxRightBordersum) maxRightBordersum = maxrightbordersum; 
        } 

        // Cross Border Sum
        int CrossBorderSum = maxRightBordersum + maxLeftBordersum;
        return max(CrossBorderSum, max(maxleftsum, maxrightsum));
    }

    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size()-1);
    }
};