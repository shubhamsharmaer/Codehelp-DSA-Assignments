class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // take a ans string
        string ans;
        // take a int
        int i = 0;

        while(true){
            // taking a char for comparing the chars of str
            char cur_ch = 0;

            // loop for iterating strs
            for(auto str:strs){

                // check for out of bound
                // eg 6 chars -> 'flower' 4 chars -> 'flow'
                if(i >= str.size()){
                    cur_ch = 0;
                    break;
                }
                if(cur_ch == 0){
                    cur_ch = str[i];
                }
                else if(str[i] != cur_ch){
                    cur_ch = 0;
                    break;
                }
            }

            // cond for exit while loop
            if(cur_ch == 0){
                break;
            }
            ans.push_back(cur_ch);
            i++;
        }

        return ans;
        
    }
};