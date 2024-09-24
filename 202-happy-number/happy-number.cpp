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
        int sum = 0; // take a sum int
        while(n > 0){
            int digit = n % 10; // extract the last digit
            sum += digit * digit; // take square and add to sum
            n /= 10; // extract each digit
        }

        return sum;

    }
    bool isHappy(int n) {
        int slow = n;
        int fast = getnext(n);
        while(fast != 1 && slow != fast){
            slow = getnext(slow);
            fast = getnext(getnext(fast));
        }
        return fast == 1;
    }
};