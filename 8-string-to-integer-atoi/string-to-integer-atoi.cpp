class Solution {
public:
    int myAtoi(string s) {
        // ignore white spaces
        // determine 'sign' (- or +)
        // if digit found -> convert it to int type

        // take int var
        int num = 0, i = 0, sign = 1;

        // loop for string
        while(s[i] == ' '){
            i++;
        }
            // check sign with outer bound codn
            if(i < s.size() && s[i] == '-' || s[i] == '+'){
                sign = s[i] == '+' ? 1 : -1;
                ++i;
            }

            // next to check numbers till non-digit
            while(i < s.size() && isdigit(s[i])){
                // iss loop ma only foll cases enter hogne
                // e.g -> "____123hello", "___-1"

                // out of bound check
                // 
                if(num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7')){
                    return sign == -1 ? INT_MIN : INT_MAX;
                }
                num = num * 10 + (s[i] - '0');
                ++i;

            }

            // cases like -> "____", "___hello", non-digit string
            // inn cases ma upper vale while loop ma  nhi jayegi
            // hum sitha num return krdege with sign 
        return num*sign;
    }
};