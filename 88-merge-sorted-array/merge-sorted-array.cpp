class Solution {
public:
    // Pointers Setup:
    // Teen pointers use karo: i -> nums1 ke end ke liye, 
    //                         j -> nums2 ke end ke liye, 
    //                         k -> ek nums1 ke last position ke liye.

    // Compare from End with Loop: -> while(i >= 0 && j >= 0) 
    //                                  -> if([i] > [j]) then nums1[k--] = nums[i--]
    //                                  -> else -> nums1[k--] = nums2[j--]

    // Copy bache hue elem: while(j >= 0) -> nums1[k--] = nums[j--];

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
            }
        }

        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }
};