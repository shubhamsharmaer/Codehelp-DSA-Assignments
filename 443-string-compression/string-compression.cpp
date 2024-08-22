class Solution {
public:
    int compress(vector<char>& chars) {
        // take 3 var 
            // 1 index -> for in place changes
            // 2 count -> for counting chars
            // 3 prev -> for matching with curr i
        // loop for travers
            // if([i] == prev) -> count++;
            // else 
                    // [index++] = prev
                    // if(count > 1) 
                        // store count in form of chars in reverse -> SEE CODE
                    // update prev -> prev = i;
                    // reset count -> count = 1;  
        int index = 0, count = 1;
        char prev = chars[0];

        for(int i = 1; i < chars.size(); i++){
            if(chars[i] == prev){
                count++;
            }
            else{
                chars[index++] = prev;
                if(count > 1){
                    //-----------------------//
                    int start = index; 
                    while(count){
                        chars[index++] = (count % 10) + '0';
                        count /= 10;
                    }
                    reverse(chars.begin() + start, chars.begin() + index);
                    //---------------------------------------------------//
                }
                prev = chars[i];
                count = 1;
            }
        }
        chars[index++] = prev;
        if(count > 1){
            int start = index;
            while(count){
                chars[index++] = (count % 10) + '0';
                count /= 10;
            }
            reverse(chars.begin() + start, chars.begin() + index);
        }
        return index;
    }
};