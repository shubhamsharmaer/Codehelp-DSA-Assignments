class Solution {
public:

    bool isVowel(char ch){
        string str = "aeiouAEIOU";
        if(str.find(ch) != string::npos){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int l = 0;
        int h = s.size() - 1;

        while(l<h){
            if(isVowel(s[l]) && isVowel(s[h])){
                swap(s[l], s[h]);
                l++;
                h--;
            }
            else if(!isVowel(s[l])){
                l++;
            }
            else{
                h--;
            }
        }
        return s;
    }
};