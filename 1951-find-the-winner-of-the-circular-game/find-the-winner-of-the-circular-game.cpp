class Solution {
public:
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