class Solution {
public:
    void findmaxprofit(vector<int>& prices, int i, int& minProfit, int& maxProfit){
        // base case
        if(i == prices.size()) return;

        // ek case solve krna ha
        if(prices[i] < minProfit) minProfit = prices[i];
        int todayprofit = prices[i] - minProfit;
        if(todayprofit > maxProfit){
            maxProfit = todayprofit;
        }

        // recursive call
        return findmaxprofit(prices, i+1, minProfit, maxProfit);
    }
       
    int maxProfit(vector<int>& prices) {
       int maxProfit = INT_MIN;
       int minProfit = INT_MAX;
       findmaxprofit(prices, 0, minProfit, maxProfit);
       return maxProfit;
    }
};