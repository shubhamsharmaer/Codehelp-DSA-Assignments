class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // take a map
        unordered_map<int, int> map;
        // do mapping
        for(auto item : nums){
            map[item]++;
        } 

        // check for duplicate
        for(const auto& item : map){
            if(item.second > 1) return true;
        }
        return false;
    }
};