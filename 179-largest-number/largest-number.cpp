class Solution {
public:
    // take a vector<string> snums
    // loop on nums for storing int in snums with to_string() fn
    // sort snums with custom compatitor
    // custom mycom -> take 2 strings as argms
                 // -> two strings sum 
                 // -> return t1 > t2

    // EDGE CASE [0,0] O/P -> 0 -> if(snums[0] == "0") return "0";
    
    static bool mycom(string a, string b){
        string t1 = a+b;
        string t2 = b+a;
        return t1 > t2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for(auto num: nums){
            snums.push_back(to_string(num));
        }

        sort(snums.begin(), snums.end(), mycom);
        string ans = "";
        
        if(snums[0] == "0") return "0";
        
        for(int i = 0; i < snums.size(); i++){
            ans += snums[i];
        }
        return ans;
    }
};