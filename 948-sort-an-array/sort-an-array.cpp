class Solution {
public:
    // take temp vector
    // call mergeSort(nums, temp, 0, nums.size()-1)
        // base case -> if(start >= end) return
        // break into 2 sub array -> mergeSort(nums, temp, start, mid)
                            //    -> mergeSort(nums, temp, mid+1, end)
        // call mergeSort(nums, temp, start, mid, end)
            // take i = start, j = mid+1; k = start
            // while(i <= mid && j <= end) -> for merging 2 subarr
            // while(i <= mid) -> for any left num in left arr
            // while(j <= end) -> for any left num in right arr
            // while(start <= end) -> for copying temp arr into original nums
    void merge(vector<int>& nums, vector<int>& temp, int start, int mid, int end){
        int i = start, j = mid+1, k = start;

        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                temp[k++] = nums[j++];
            }
        }

        while(i <= mid){
            temp[k++] = nums[i++];
        }
        while(j <= end){
            temp[k++] = nums[j++];
        }

        while(start <= end){
            nums[start] = temp[start];
            ++start;
        }
    }
    void mergeSort(vector<int>& nums, vector<int>& temp, int start, int end){
        //base case
        if(start >= end) return;

        int mid = start + (end-start) / 2;

        mergeSort(nums, temp, start, mid);
        mergeSort(nums, temp, mid+1, end);

        merge(nums, temp, start, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, temp, 0, nums.size()-1);
        return nums;
    }
};