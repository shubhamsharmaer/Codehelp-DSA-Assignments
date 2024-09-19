class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // take the characters out from string using loop
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    if(ch == ')'  && st.top() == '('){
                        st.pop();
                    }
                    else if(ch == '}'  && st.top() == '{'){
                        st.pop();
                    }
                    else if(ch == ']'  && st.top() == '['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        // check if stack is empty or not
        if(st.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }
};