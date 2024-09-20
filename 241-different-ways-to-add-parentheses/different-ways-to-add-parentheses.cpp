class Solution {
public:
        // take ans vec
        // loop on str
        // check for oprts
                // make two ans1 and ans2 with RE Call
                // nested loops
                        // check for optrs individauly --> if(exp[i] == '+') then ans.push_back(1[] + 2[])
        // base case --> if ans.size() == 0 push stoi(exp) in ans
    
    vector<int> helper(string exp){
        // take ans vec
        vector<int> ans;
        // loop on str
        for(int i = 0; i < exp.size(); i++){
            if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*'){
                // make two ans1 and ans2 with RE Call
                vector<int> ans1 = helper(exp.substr(0, i));
                vector<int> ans2 = helper(exp.substr(i+1));

                // nested loops
                for(int j = 0; j < ans1.size(); j++){
                    for(int k = 0; k < ans2.size(); k++){
                        // check for optrs
                        if(exp[i] == '+'){
                            ans.push_back(ans1[j] + ans2[k]);
                        }
                        else if(exp[i] == '-'){
                            ans.push_back(ans1[j] - ans2[k]);
                        }
                        else{
                            ans.push_back(ans1[j] * ans2[k]);
                        }
                    }
                }
            }
        }
        // base case
        if(ans.size() == 0){
            ans.push_back(stoi(exp));
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return helper(expression);
    }
};