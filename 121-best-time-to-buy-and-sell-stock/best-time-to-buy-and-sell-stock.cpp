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
    
    void findProfit(vector<int>& prices, int i, int& minProfit, int& maxProfit){
        // base case
        if(i == prices.size()) return;
        // soln for 1 case
            if(prices[i] < minProfit) minProfit = prices[i];
            int todayprofit = prices[i] - minProfit;
            if(todayprofit > maxProfit){
                maxProfit = todayprofit;
            }
        // recusive call
        findProfit(prices, i+1, minProfit, maxProfit);
    }
    int maxProfit(vector<int>& prices) {
        int minProfit = INT_MAX;
        int maxProfit = INT_MIN;
        int i = 0;
        findProfit(prices, i, minProfit, maxProfit);
        return maxProfit;
    }
};