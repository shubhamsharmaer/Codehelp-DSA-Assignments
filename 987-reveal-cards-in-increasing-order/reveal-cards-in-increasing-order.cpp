class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // sort the deck
        sort(deck.begin(), deck.end());
        int n = deck.size();
        // take a ans vec
        vector<int> ans(n);
        // take a queue
        queue<int> q;

        // loop for inserting indx in que
        for(int i = 0; i < ans.size(); i++)
            q.push(i);

        for(int i = 0; i < n; i++){
            // while(!q.empty()){
                // 1. push in ans
                    ans[q.front()] = deck[i];
                    q.pop();
                // 2. back to bottom
                    if(!q.empty()){
                        auto next = q.front();
                        q.push(next);
                        q.pop();
                    }
            // }
        }   
        return ans;
    }
};