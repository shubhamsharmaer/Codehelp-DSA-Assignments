class Solution {
public:
    // take two pointers i,j
    // loop while (j < t.size())
    //      if [i] == [j] move i++
    //      j++
    //      if i == s.size() return true;
    // return false;
    bool isSubsequence(string s, string t) {
       int i = 0, j = 0;
        if(s.empty() && t.empty()){
                return true;
            }
       while(j < t.size()){
            if(s[i] == t[j]){
                i++;
            }
            j++;
            if(i == s.size()){
                return true;
            }
       }
       return false;
    }
};