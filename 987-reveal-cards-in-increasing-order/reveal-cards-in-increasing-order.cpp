class Solution {
public:
    // Using Simulating the Game ---> Reverse Simulation
    //       DECK [], QUEUE (), ANS []
    // SORT THE DECK []
    // QUEUE (1,2,3,4,5,.....N) -----> PUSH INDEX OF ANS
    // 1. ANS [Q.FRONT()] = DECK[i] -----> Ans vec ma using q's indx deck ki values daalo
    // then pop()
    // 2. if(!q.empty) then q.push(q.front()), pop() ----> bottom ma front ki value daalo
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n = deck.size();
        vector<int> ans(deck.size());
        queue<int> q;
        // push the indx of ans ---> queue
        for(int i = 0; i < ans.size(); i++)
            q.push(i);
        // reverse simulation 
        for(int i = 0; i < n; i++){
            // 1. copy q value indx to ans 
            ans[q.front()] = deck[i];
            q.pop();

            // 2. push back to bottom
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};