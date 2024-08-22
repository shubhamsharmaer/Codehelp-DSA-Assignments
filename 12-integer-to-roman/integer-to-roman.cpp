class Solution {
public:
    string intToRoman(int num) {
        // make roman symbols string
        // make corresponding array of int
        // take an ans string
        // loop on symbol length (13) -> while(num >= values)
                                            // ans += romansym[i]
                                            // num -= values[i]
        //return ans;
        string Romansymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", 
                                "X", "IX", "V", "IV", "I"};
        int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

        string ans = "";

        for(int i = 0; i < 13; i++){
            while(num >= values[i]){
                ans += Romansymbols[i];
                num -= values[i];
            }
        }
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // for(int i = 0; i < 13; i++){
        //     while(num >= values[i]){
        //         ans += Romansymbols[i];
        //         num -=values[i];
        //     }
        // }
        // return ans;
    }
};