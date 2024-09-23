class Solution {
public:
    int solve(int i, string s, unordered_set<string>& st, int& n, unordered_map<int, int>& mp){
        if(i >= n) return 0;

        int ans = 1 + solve(i+1, s, st, n, mp);
        
        if(mp.count(i)){
            return mp[i];
        }
        // not skip i = 0
        for(int j  = i; j < n; j++){
            string cur = s.substr(i, j-i+1);
            if(st.count(cur)){
                // valid
                ans = min(ans, solve(j+1, s, st, n, mp));
            }
        }
        return mp[i] = ans;
        
    }
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.size();
        unordered_set<string> st(begin(dict), end(dict));
        unordered_map<int, int> mp;
        return solve(0, s, st, n, mp);

    }
};