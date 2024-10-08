class Solution {
public:
    // take a set string for dic
    // take a map int, int for s
    // call solve (0, s, set, map, n)
    // logic for solve ---> base i >= n return 0
    //                 ---> take int ans = i+1, baki same
    //                 ---> check if [i] count in mp then return mp[i]
    //                 ---> for loop j = i < n
    //                      ---> take a curr string = s.substr(i, j-i+1)
    //                      ---> check if st.count(curr) then ans = min(ans, solve(j+1, same))
    //          --> return mp[i] = ans;
    int solve(int i, string& s, unordered_set<string>& st, unordered_map<int, int>& map, int n){
        // base cond
        if(i >= n) return 0;
        
        int ans = 1 + solve(i+1, s, st, map, n);
        if(map.count(i)){
            return map[i];
        }

        for(int j = i; j < n; j++){
            string cur = s.substr(i, j-i+1);
            if(st.count(cur)){
                ans = min(ans, solve(j+1, s, st, map, n));
            }
        }
        return map[i] = ans;
    }
    int minExtraChar(string s, vector<string>& dic) {
        int n = s.size();
        unordered_set<string> st(begin(dic), end(dic));
        unordered_map<int, int> map;
        int ans = solve(0, s, st, map, n);
        return ans;
    }
};