class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minprefix = 0;
        int prefix = 0;
        for(auto num : nums){
            prefix += num;
            minprefix = min(minprefix, prefix);
        }
        return 1 - minprefix; // YHA MA GALTI KRUGA
    }
};