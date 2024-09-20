class Solution {
public:
    // s ko original string ma store kar
    // take str = s
    // reverse s
    // then add str += '*' + s;
    // KMP Applying
        // check match --> j ma i+1 daal or i, j ko ++ kar
        // check break cond
        // check not match
            // two case
            // case 1 --> i > 0
    // take diff for to get shortest palindrome string
    // add that range from 0 to diff in original string --> s.substr(0, diff) + origianl
    string shortestPalindrome(string s) {
    int n = s.size();
    string original = s;
    string str = s;
    reverse(s.begin(), s.end());
    str += '*' + s;

    // KMP Applying
    vector<int> lps(2*n+1);
    int i = 0, j = 1;

    while(j < str.size()){
        // check match --> j ma i+1 daal or i, j ko ++ kar
        if(str[i] == str[j]){
            lps[j] = i+1; 
            i++;
            j++;
        }
        // check break cond
        if(j == str.size()){
            break;
        }
        // check not match
        if(str[i] != str[j]){
            // two case
            // case 1 --> i > 0
            if(i > 0){
                i = lps[i-1];
            }
            // else --> j ma 0 daal or j++ kar
            else{
                lps[j] = 0;
                j++;
            }
        }
    }
    // take diff for to get shortest palindrome string
    int diff = n - lps[2*n];
    // add that range from 0 to diff in original string
    original =  s.substr(0, diff) + original;
    // return that string than
    return original;
        
    }
};