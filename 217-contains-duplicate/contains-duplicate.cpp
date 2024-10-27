class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto it : nums){
            map[it]++;
        }

        // check for freq
        for(const auto& pair : map){
            if(pair.second > 1) return true;
        }
        return false;

    }
};