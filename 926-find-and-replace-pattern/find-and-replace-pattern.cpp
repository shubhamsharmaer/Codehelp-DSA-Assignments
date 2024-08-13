class Solution {
public:

    void createmapping(string&str){
        // create mapping
        char start = 'a';
        char mapping[256] = {0};

        for(auto ch:str){
            if(mapping[ch] == 0){
                mapping[ch] = start;
                start++;
            }
        }


        // update string
        for(int i = 0; i < str.length(); i++){
            str[i] = mapping[str[i]];
        }
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        // normalize the pattern
        createmapping(pattern);
        
        vector<string> ans;

        // take strings from words
        for(auto s: words){
            string temp = s;
            // normalize temp
            createmapping(temp);
            if(temp == pattern){
                ans.push_back(s);
            }
        }
        return ans;
    }
};