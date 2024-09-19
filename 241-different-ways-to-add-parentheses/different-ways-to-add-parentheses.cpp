class Solution {
public:
    vector<int> helper(string exp){
        vector<int> ans;
        
        // loop on string
        for(int i = 0; i < exp.size(); i++){
            // cond for opr check
            if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*'){
                // make two ans
                vector<int> ans1 = helper(exp.substr(0, i));
                vector<int> ans2 = helper(exp.substr(i+1));

                // loop on both ans1 and ans2
                for(int j = 0; j < ans1.size(); j++){
                    for(int k = 0; k < ans2.size(); k++){
                        // check for oprts
                        if(exp[i] == '+') ans.push_back(ans1[j] + ans2[k]);
                        else if(exp[i] == '-') ans.push_back(ans1[j] - ans2[k]);
                        else ans.push_back(ans1[j] * ans2[k]);
                    }
                }
            }
            
        }
        // base case
        if(ans.size() == 0) ans.push_back(stoi(exp));
        return ans;

    }
    vector<int> diffWaysToCompute(string expression) {
        return helper(expression);
    }
};