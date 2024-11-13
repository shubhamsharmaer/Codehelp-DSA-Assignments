class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // make a unoredered_set for vowels
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        // int m = words.size();
        vector<int> findvowelnum;
        
        // take string out of words
        for(auto& str : words){
            if(vowels.find(str.front()) != vowels.end() && 
            vowels.find(str.back()) != vowels.end()){
                findvowelnum.push_back(1);
            }
            else{
                findvowelnum.push_back(0);
            }
        }
        int n = findvowelnum.size();

        // calculating prefixsum
        vector<int> prefixsum(n);
        prefixsum[0] = findvowelnum[0];
        for(int i = 1; i < findvowelnum.size(); i++){
            prefixsum[i] += prefixsum[i - 1] + findvowelnum[i]; 
        }

        vector<int> ans;
        int left = 0;
        int right = 0;
        int val = 0;
        for(auto& range : queries){
            // now range is like [x, y]
            left = range[0];
            right = range[1];

            if(left == 0){
                val = prefixsum[right];
            }
            else{
                val = prefixsum[right] - prefixsum[left - 1];
            }
                ans.push_back(val);
        }
       
        return ans;
    }
};