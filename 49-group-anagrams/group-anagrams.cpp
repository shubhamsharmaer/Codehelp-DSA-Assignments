class Solution {
public:
    // make a map <std::array<int, 256>, vector<string>>mp;
    // loop for str : strs
    //          mp[hash[str]].push_back(str)
    // take ans vector<vector>
    // loop for mp
    // hash() --> create mapping 
    //          take std::array<int, 256> hash = {0};
    // loop for auto it = mp.begin(); it != mp.end(); it++
    //          ans.push_back(it -> second)
    // return ans;
    // loop for string argr s
    //          hash[s[i]]++;
    // return hash;
    std::array<int, 256> hash(string s){
        std::array<int, 256> hash = {0};
        for(int i = 0; i < s.size(); i++){
            hash[s[i]]++;
        }
        return hash;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // take a map
        map<std::array<int, 256>, vector<string>>mp;
        for(auto str : strs){
            mp[hash(str)].push_back(str);
        }

        vector<vector<string>>ans;

        for(auto it = mp.begin(); it != mp.end(); it++){
            // push second elem
            ans.push_back(it -> second);
        }
        return ans;
    }
};