//* https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
//* https://youtu.be/excAOvwF_Wk

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int mini = prices[0];

        for(int i = 1; i < prices.size(); ++i){
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }

        return maxProfit;
    }
};