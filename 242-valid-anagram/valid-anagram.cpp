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
        // loop for freq counting
        // loop for decrementing the counting
        // return true
        int freq[256] = {0};

        for(int i = 0; i < s.length(); i++){
            freq[s[i]]++;
        }

        for(int j = 0; j < t.length(); j++){
            freq[t[j]]--;
        }

        for(int i = 0; i < 256; i++){
            if(freq[i] != 0){
                return false;
            }
        }
        return true;
    }
};