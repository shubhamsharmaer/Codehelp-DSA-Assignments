class Solution {
public:
    // take a map 
    vector<pair<int, string>>mp = {{1000000000, "Billion"}, {1000000, "Million"},
    {1000, "Thousand"}, {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"},
    {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"},
    {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"},
    {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"},
    {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"},
    {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"},
    {2, "Two"}, {1, "One"}
    };
    string numberToWords(int num) {
        // base case
        if(num == 0) return "Zero";

        // ek case solve krna ha
        for(auto it:mp){
            // condn check for if it > or = to mp.first
            if(num >= it.first){
                // string a
                string a = "";
                if(num >= 100){
                    // recusive call
                    a = numberToWords(num / it.first) + " ";
                }
                // string b
                string b = it.second;
                // string c
                string c = "";
                if(num % it.first != 0){
                    c = " " + numberToWords(num % it.first);
                }
                return a + b + c;
            }
        }
        return "";
    }
};