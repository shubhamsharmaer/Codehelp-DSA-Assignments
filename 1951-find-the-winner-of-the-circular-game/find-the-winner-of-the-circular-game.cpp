class Solution {
public:
    // take a queue
    // push all from 0 --> n in qu
    // pop element with k gap ----
    // when qu left with one element then it will be winner of the game

    int findTheWinner(int n, int k) {
        // take a queue
        queue<int> q;
        for(int i = 1; i <= n; i++)
            q.push(i);
        
            while(q.size() != 1){
                for(int i = 1; i < k; i++){
                    auto player = q.front();
                    q.pop();
                    // push back the players
                    q.push(player);
                }
                q.pop();
            }
        return q.front();
    }
};