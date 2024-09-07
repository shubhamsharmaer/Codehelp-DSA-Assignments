class Solution {
public:
    // take a ans string to store matched char
        // take a int
            // taking a char for comparing the chars of str
            // loop for iterating strs (auto str: strs)
                // check for out of bound if(i >= str.size()) -> reset curr_ch = 0, break;
                // eg 6 chars -> 'flower' 4 chars -> 'flow'
            // cond for exit while loop
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int i = 0;

        while(true){
            char curr_ch = 0;
            for(auto str : strs){
                if(i >= str.size()){
                    curr_ch = 0;
                    break;
                }
                else if(curr_ch == 0){
                    curr_ch = str[i];
                }
                else if(curr_ch != str[i]){
                    curr_ch = 0;
                    break;
                }
            }
            if(curr_ch == 0) break;
            ans.push_back(curr_ch);
            i++;
        }
            return ans;
    }
};