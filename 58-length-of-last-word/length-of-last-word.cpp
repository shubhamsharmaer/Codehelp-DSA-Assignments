class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.size()-1;
        
        // skip spaces
        while(i >= 0 && s[i] == ' '){
            i--;
        }

        // count alphabets
        while(i >= 0 && isalpha(s[i])){
            len++;
            i--;
        }

        return len;
    }
};