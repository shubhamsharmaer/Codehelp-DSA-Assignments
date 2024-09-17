class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        std::unordered_map<std::string, int> wordCount;
        std::vector<std::string> ans;  

        auto mapping = [&](std::string& str){
            // take words from string
            std::istringstream stream(str);
            // take a sting word
            std::string word;
            while(stream >> word){
                wordCount[word]++;
            }
        };

        // map of both s1 and s2
        mapping(s1);
        mapping(s2);

        // check for uncommon
        for(const auto& entry : wordCount){
            if(entry.second == 1){
                // push first(string) into ans
                ans.push_back(entry.first);
            }
        }
        return ans;
    }
};