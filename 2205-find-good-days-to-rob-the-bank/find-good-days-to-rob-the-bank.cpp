class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        // prefix arr from i - time to i - 1
        vector<int>prefix(n, 0);
        prefix[0] = 0;
        vector<int>suffix(n, 0);
        suffix[n-1] = 0;

        // finding the increasing arr
        for(int i = 1; i < n; i++){
            if(security[i] <= security[i-1]){
                prefix[i] = prefix[i - 1] + 1;
            }
        }

        // finding decreasing arr
        for(int i = n - 2; i >= 0; i--){
            if(security[i] <= security[i+1]){
                suffix[i] = suffix[i + 1] + 1;
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(prefix[i] >= time && suffix[i] >= time){
                ans.push_back(i);
            }
        }
        return ans;
    }
};