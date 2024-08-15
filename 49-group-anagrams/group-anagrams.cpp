class Solution {
public:
    // std::array<int, 256>hash(string s){
    //     // make a hash
    //     std::array<int,256>hash = {0};
    //     for(int i = 0; i < s.size(); i++){
    //         hash[s[i]]++;
    //     }
    //     return hash;
    // }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // create map
        map<string, vector<string>>mp;
        // M2 -> map<std::array<int,256>, vector<string>>mp;
        
        // loop on strs
        for(auto str:strs){
            // take a string say -> s
            string s = str;
            // sort s
            sort(s.begin(), s.end());
            mp[s].push_back(str);
            // M2 -> mp[hash(s)].push_back(str);
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