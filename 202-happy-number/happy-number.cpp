class Solution {
public:
    // while (n > 0) 
        // take a sum int
        // extract the last digit
        // take square and add to sum
        // extract each digit
    
    //  init slow with n and fast funcall(n)
    // while fast != 1 && slow != fast --> call slow one time and fast 2 time
    int getnext(int n){
        int sum = 0;

        while(n > 0){
            int digit = n % 10;
            sum += digit*digit;
            n /= 10;    
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = getnext(n);

        while(fast != 1 && slow != fast){
            fast = getnext(getnext(fast));
            slow = getnext(slow);
        }

        return fast == 1;

    }
};