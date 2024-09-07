class Solution {
public:
    // find pivot
    // apply binary search
    // apply bs on left side bs()
    // apply bs on right side
    int findpivot(vector<int>& nums){
        int n = nums.size();
        int s = 0, e = nums.size()-1;

        while(s <= e){
            int mid = s + (e - s) / 2;

            // corner case -> one element
            if(s == e) return s;

            // condn's
            if(mid + 1 < n && nums[mid] > nums[mid + 1]){
                return mid;
            }
            else if(mid - 1 >= 0 && nums[mid] < nums[mid - 1]){
                return mid - 1;
            }
            else if(nums[mid] >= nums[s]){
                s = mid + 1;  // search on the right side
            }
            else{
                e = mid - 1;  // search on the left side
            }
        }
        return -1;
    }
    int bs(vector<int>& nums, int s, int e, int target){
        while(s <= e){
            int mid = s + (e-s) / 2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                // go to left
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findpivot(nums);
        int ans = -1;
        // apply bs
        if(target >= nums[0] && target <= nums[pivot]){
            ans = bs(nums, 0, pivot, target);
        }
        else{
            ans = bs(nums, pivot + 1, n - 1, target);
        }
        return ans;
    }
};