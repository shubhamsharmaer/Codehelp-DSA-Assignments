class Solution {
public:
    bool isAnagram(string s, string t) {
        // M1 Sorting
        // Sort both strings
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // Compare the sorted strings
        // return s == t;

        // M2 -> Freqtable or Hash
        int freq[256] = {0};

        // loop for freq counting
        for(int i = 0; i< s.size(); i++){
            freq[s[i]]++;
        }

        // loop for decrementing the counting
        for(int i = 0; i<t.size(); i++){
            freq[t[i]]--;
        }

        for(int i = 0; i < 256; i++){
            if(freq[i] != 0){
                return false;
            }
        }
        return true;
    }
};