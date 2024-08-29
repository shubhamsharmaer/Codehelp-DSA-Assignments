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
        // base case
        if(start == end) return v[start];
        int mid = start + ((end - start) / 2);
        int maxLeftBordersum = INT_MIN, maxRightBordersum = INT_MIN;

        // recusive call
        int maxleftsum = maxSubArrayHelper(v, start, mid);
        int maxrightsum = maxSubArrayHelper(v, mid+1, end);

        // CROSS BORDER SUM
        int leftbordersum = 0, rightbordersum = 0;
        // left sum
        for(int i = mid; i >= start; i--){
            leftbordersum += v[i];
            if(leftbordersum > maxLeftBordersum) maxLeftBordersum = leftbordersum; 
        }
        // right sum
        for(int i = mid+1; i <= end; i++){
            rightbordersum += v[i];
            if(rightbordersum > maxRightBordersum) maxRightBordersum = rightbordersum; 
        }
        int CrossBorderSum = maxRightBordersum + maxLeftBordersum;

        return max(CrossBorderSum, max(maxrightsum, maxleftsum));

    }
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size()-1);
    }
};