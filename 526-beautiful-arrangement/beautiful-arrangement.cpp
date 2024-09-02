class Solution {
public:

    // take an v vector for storing all arrangments
    // inside helper fun -> base case
    //                      -> if currNum == n + 1 then ans++; return;
    //                   -> loop (1 -> <= n)
    //                      check if (v[i] == 0 && (i % currNum == 0 || opposite))
    //                          then v[i] = currNum
    //                          recursive call with currNum + 1;
    //                          then put 0 to v[i]; 
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