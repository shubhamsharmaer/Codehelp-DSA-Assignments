class Solution {
public:
    string addRE(string num1, int p1, string num2, int p2, int carry = 0){
        // base case - when to stop?
        if(p1 < 0 && p2 < 0){
            // handle carry if any
            if(carry != 0){
                return string(1, carry + '0'); 
            }
            return "";
        }



        // ek case solve krna ha
        //-------------------------//
        // take value from strings
        int n1 = (p1 >= 0 ? num1[p1] : '0')- '0';
        int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';

        // take sum
        int csum = n1 + n2 + carry;
        // take last digit of sum
        int digit = csum % 10;
        // take carry if any
        carry = csum / 10;

        // take an ans string
        string ans = "";
        // push digit in ans
        ans.push_back(digit + '0');
        // ---------------------------- //

        // recusive call
        ans += addRE(num1, p1 - 1, num2, p2 - 1, carry);
        return ans;
    }
    string addStrings(string num1, string num2) {
        string ans = addRE(num1, num1.size()-1, num2, num2.size() - 1);
        reverse(ans.begin(), ans.end());
        return ans;

    }
};