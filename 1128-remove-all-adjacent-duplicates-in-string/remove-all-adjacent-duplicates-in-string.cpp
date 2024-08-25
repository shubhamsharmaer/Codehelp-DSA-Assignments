class Solution {
public:
    string removeDuplicates(string s) {
        // make a ans string
        // take an index
        // loop for traver
            // if same appears (ans[ans.length()-1] == s[index]) with explicit range overflow cond -> ans.length() > 0
                // pop_back from ans
            // else
            // push_back in ans


        string ans = "";
        int index = 0;

        while(index < s.length()){
            if(ans.length() > 0 && ans[ans.length()-1] == s[index]){
                ans.pop_back();
            }
            else{
                ans.push_back(s[index]);
            }
            index++;
        }
        
        return ans;
    }
};