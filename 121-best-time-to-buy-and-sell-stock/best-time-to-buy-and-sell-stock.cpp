class Solution {
public:
    void findmaxprofit(vector<int>& prices, int i, int& minProfit, int& maxProfit){
        // base case
        if(i == prices.size()) return;
        // ek case solve kro
        if(prices[i] < minProfit) minProfit = prices[i];
        int todayProfit = prices[i] - minProfit; 
        if(todayProfit > maxProfit){
            maxProfit = todayProfit;
        }
        // recusive call
        findmaxprofit(prices, i+1, minProfit, maxProfit);
    }
    int maxProfit(vector<int>& prices) {
        int minProfit = INT_MAX;
        int maxProfit = INT_MIN;
        findmaxprofit(prices, 0, minProfit, maxProfit);
        return maxProfit;
    }
};