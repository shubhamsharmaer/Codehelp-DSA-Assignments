class Solution {
public:
    // In-Place Merging
    // call mergeSort(nums, 0, nums.size()-1)
        // base case -> if(start >= end) return
        // break into 2 sub array -> mergeSort(nums, start, mid)
                            //    -> mergeSort(nums, mid+1, end)
        // call mergeInPlace(nums, start, mid, end)
            // take total_len = end - start + 1, i = start, j = gap + start
            // while(gap > 0)
                // while(j <= end)
                    // if([i] > [j]) -> swap(i,j);
                    // i++,j++
            // update the gap = gap <= 1 ? 0 : (gap/2) + (gap%2); 
    void mergeInPlace(vector<int>& nums, int start, int mid, int end){
        int total_length = end - start + 1;
        int gap = (total_length/2) + (total_length%2);

        while(gap > 0){
            int i = start;
            int j = gap + start;

            while(j <= end){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
                i++,j++;
            }
                // update the gap
                gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
        }
    }
    void mergeSort(vector<int>& nums, int start, int end){
        //base case
        if(start >= end) return;

        int mid = start + (end-start) / 2;

        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);

        mergeInPlace(nums, start, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};