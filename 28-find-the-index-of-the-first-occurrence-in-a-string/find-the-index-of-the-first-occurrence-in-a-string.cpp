class Solution {
public:
    int strStr(string haystack, string needle) {
        // STL Method | QUICK
        //---------------------------------//
        // size_t pos = haystack.find(needle);
        // if(pos != string :: npos){
            // return pos;
        // }
        // return -1;
        //---------------------------------//


        // M2 TWO POINTER
        int n = haystack.size();
        int m = needle.size();

        for(int i = 0; i <= n-m; i++){
            for(int j = 0; j < m; j++){
                if(needle[j] != haystack[i+j]){
                    break;
                }
                if(j == m-1){
                    return i;
                }
            }
        }
        return -1;
    }
};