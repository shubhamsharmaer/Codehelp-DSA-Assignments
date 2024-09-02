class Solution {
public:
    void countArrangementHelper(int& ans, vector<int>&v, int& n, int currNum){
        // base case
        if(currNum == n + 1){
            ++ans;
            return;
        }
        // loop
        for(int i = 1; i <= n; i++){
            if(v[i] == 0 && (i % currNum == 0 || currNum % i == 0)){
                v[i] = currNum;
                countArrangementHelper(ans, v, n, currNum + 1);
                v[i] = 0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int> v(n + 1);
        int ans = 0;
        countArrangementHelper(ans, v, n, 1);
        return ans;
    }
};