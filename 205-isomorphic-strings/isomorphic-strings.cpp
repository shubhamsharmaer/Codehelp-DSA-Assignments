class Solution {
public:
    // Create mapping
    //         take int map = {0} for s[i] mapping
    //         take bool map = {0} to prevent duplicate mapping of t[i]
    //          loop for mapping
    //                  check if hash[s[i]] == 0 then only map
    // Check if mapping complete using same loop above 
    //              if(char(hash[s[i]] != t[i])) then false;
    bool isIsomorphic(string s, string t) {
        int hash[256] = {0};
        bool isTmapped[256] = {0};

        for(int i = 0; i < s.size(); i++){
            if(hash[s[i]] == 0 && isTmapped[t[i]] == 0){
                hash[s[i]] = t[i];
                isTmapped[t[i]] = true;
            }
        }

        for(int i = 0; i < s.size(); i++){
            if(char(hash[s[i]] != t[i])){
                return false;
            }
        }
        return true;
    }
};