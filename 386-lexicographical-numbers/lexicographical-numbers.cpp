class Solution {
public:
    // solve with DFS Recursion
    // take a ans vec, loop 1 --> <=9 
    //                  call fun(i,n,ans)
    // DFS Fun(curr, &n, &ans)
    //          if cur > n return, push cur in ans
    //          loop for 0 --> <= 9, RE Call (cur*10+1, n, ans)
    void dfs(int cur, int& n, vector<int>& ans){
        // check for if cur > n
        if(cur > n) return;

        // push in ans
        ans.push_back(cur);
        for(int i = 0; i <= 9; i++){
            if(cur*10+i > n) break;
            dfs(cur*10+i, n, ans);
        } 
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i = 1; i<= 9; i++){
            dfs(i,n,ans);
        }
        return ans;
    }
};