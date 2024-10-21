class Solution {
public:
    // take a queue
    // push all from 0 --> n in qu
    // pop element with k gap
    // when qu left with one element then it will be winner of the game
    int findTheWinner(int n, int k) {
        queue<int> qu;
        for(int i = 1; i <= n; i++)
            qu.push(i);

            while(qu.size() > 1){
                // simulate the game
                for(int i = 1; i<k; i++){
                    // pop the kth
                    auto player = qu.front();
                    qu.pop();

                    // take back them as well
                    qu.push(player);
                }
                qu.pop();
            }
        return qu.front();

    }
};