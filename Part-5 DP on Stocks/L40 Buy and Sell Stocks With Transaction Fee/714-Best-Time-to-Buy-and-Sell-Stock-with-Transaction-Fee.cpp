//* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
//* https://youtu.be/k4eK-vEmnKg

class Solution {
public:
    int soo(vector<int>& prices, int n, int fee){
        int aheadBuy = 0, aheadNotBuy = 0, currBuy = 0, currNotBuy = 0;

        for(int ind = n-1; ind >= 0; --ind){
            // buy = 0
            currNotBuy = max(prices[ind] + aheadBuy, 0 + aheadNotBuy);

            // buy = 1;
            currBuy = max(-prices[ind] - fee + aheadNotBuy, 0 + aheadBuy);

            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }

        return aheadBuy;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        //* DP Space Optimisation using variables->
        // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/945560247/
        return soo(prices, n, fee);
    }
};