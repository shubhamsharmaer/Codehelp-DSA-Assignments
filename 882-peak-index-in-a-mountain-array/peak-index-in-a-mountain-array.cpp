class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int start = 0, end = n-1;

        while(start < end){
            int mid = start + (end-start) / 2;

            // cond to check
            if(arr[mid] < arr[mid+1]){
                // at left go to right
                start = mid+1;
            }
            else{
                end = mid;
            }
        }
        return start;
    }
};