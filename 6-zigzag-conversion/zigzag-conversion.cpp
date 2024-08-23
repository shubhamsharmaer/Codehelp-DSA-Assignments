class Solution {
public:
    string convert(string s, int numRows) {
        // condc check for 1 row only
        // take a vector
        // take vars i, row
        // take a bool changedirection
        // take an infinite loop while(true){}
        if(numRows == 1) return s;
        vector<string> zigzag(numRows);
        int i = 0, row = 0;

        bool direction = 1; // 1 -> Top - bottom

        while(true){
            if(direction){
                while(row < numRows && i < s.size()){
                    zigzag[row++].push_back(s[i++]); 
                }
                row = numRows - 2;
            }
            else{
                while(row >= 0 && i < s.size()){
                    zigzag[row--].push_back(s[i++]); 
                }
                row = 1;
            }
            if(i >= s.size()){
                break;
            }
            direction = !direction;
        }
        string ans = "";
        for(int i = 0; i < zigzag.size(); i++){
            ans += zigzag[i];
        }
        return ans;
    }
};