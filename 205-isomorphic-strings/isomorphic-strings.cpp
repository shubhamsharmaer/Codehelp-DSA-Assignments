class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256] = {0}; // mapping for s string char -> t string char
        bool isTmapped[256] = {0}; // check if char of t string  

        // loop for itetrating s
        for(int i = 0; i < s.size(); i++){
            // cond check for 
            if(hash[s[i]] == 0 && isTmapped[t[i]] == 0){
                // mappe s[i] -> t[i]
                hash[s[i]] = t[i];
                // make isTmapped true for t[i] state
                isTmapped[t[i]] = true; 
            }
        }

        // loop for checking if s[i] == t[i] in terms of chars
        for(int i = 0; i < s.size(); i++){
            if(char(hash[s[i]] != t[i])){
                return false;
            }
        }

        return true;
    }
};