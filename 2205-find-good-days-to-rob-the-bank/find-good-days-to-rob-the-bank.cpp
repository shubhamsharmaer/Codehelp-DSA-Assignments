class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();

        // take two sums vec
        vector<int> prefixSum(n, 0);
        prefixSum[0] = 0;
        vector<int> suffixSum(n, 0);
        suffixSum[n-1] = 0;

        // loop for non-increasing
        for(int i = 1; i < n; i++){
            if(security[i] <= security[i - 1]){
                prefixSum[i] = prefixSum[i - 1] + 1;
            }
        }

        // loop for non-decreasing
        for(int i = n - 2; i >= 0; i--){
            if(security[i] <= security[i + 1]){
                suffixSum[i] = suffixSum[i + 1] + 1;
            }
        }

        // check for penalty
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(prefixSum[i] >= time && suffixSum[i] >= time){
                ans.push_back(i);
            }
        }
        return ans;
    }
};