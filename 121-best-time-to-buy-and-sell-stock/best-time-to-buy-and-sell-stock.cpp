class Solution {
public:
     // take 3 var -> i, minProfit, maxProfit
    // call func()
        // base case -> i == prices.size return;
        // soln for case -> if [i] < minProfit then minProfit = [i]
                    //   -> take int todayprofit = [i] - minProfit
                    //   -> if todayprofit < maxProfit then maxProfit = todayprofit
        // recusive call -> funt(prices, i+1, minProfit, maxProfit) 
    //return maxProfit
    void maxProfitHelper(vector<int>& prices, int i, int& minProfit, int& maxProfit){
        // base case
        if(i == prices.size()) return;

        // cal part
        // checking if minProfit is < or >= [i]
        if(minProfit > prices[i]) minProfit = prices[i];
        int todayProfit = prices[i] - minProfit;
        if(todayProfit > maxProfit){
            maxProfit = todayProfit;
        }

        // recursive call
         maxProfitHelper(prices, i+1, minProfit, maxProfit);
        
    }
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int minProfit = INT_MAX;
        int maxProfit = INT_MIN;
        maxProfitHelper(prices, i, minProfit, maxProfit);
        return maxProfit;
    }
};