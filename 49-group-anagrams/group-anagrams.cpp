class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // create map
        map<string, vector<string>>mp;
        
        // loop on strs
        for(auto str:strs){
            // take a string say -> s
            string s = str;
            // sort s
            sort(s.begin(), s.end());
            // map[s].push_back(str);
            mp[s].push_back(str);
        }
            
        // make a ans vector<vector<string>>
        vector<vector<string>>ans;
        // loop on map
        for(auto it = mp.begin(); it != mp.end(); it++){
            //  push second on ans
            ans.push_back(it -> second);
        }
        return ans;

        
    }
};