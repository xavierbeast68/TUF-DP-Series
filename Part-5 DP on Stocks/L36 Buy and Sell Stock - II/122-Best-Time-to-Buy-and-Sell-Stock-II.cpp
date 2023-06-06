//* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
//* https://youtu.be/nGJmxkUJQGs

class Solution {
public:
    int rec(int ind, int buy, int n, vector<int>& values, vector<vector<int>>& dp){
        // Base Case
        // end of list
        if(ind == n){
            return 0;
        }

        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }

        int profit = 0;
        // Recursive Case
        // not buyed yet-> either buy current stock or skip it
        if(buy){
            // max(boughtValue + findForSellValue, notBuyed + findForNewBuyValue)
            profit = max(-values[ind] + rec(ind+1, 0, n, values, dp),
                            0 + rec(ind+1, 1, n, values, dp));
        }
        // either sell the boughted stock at current value or skip it
        else{
            // max(soldValue + buyNewStock, notSold + findForNewSellValue)
            profit = max(values[ind] + rec(ind+1, 1, n, values, dp),
                            0 + rec(ind+1, 0, n, values, dp));
        }

        return dp[ind][buy] = profit;
    }

    int tab(vector<int>& values, int n){
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        // dp[n][0] = dp[n][1] = 0;

        for(int ind = n-1; ind >= 0; --ind){
            for(int buy = 0; buy <= 1; ++buy){
                if(buy){
                    dp[ind][buy] = max(-values[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
                }
                else{
                    dp[ind][buy] = max(values[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
                }
            }
        }

        return dp[0][1];
    }

    int so(vector<int>& values, int n){
        vector<int> ahead(2, 0), curr(2, 0);

        // ahead[0] = ahead[1] = 0;

        for(int ind = n-1; ind >= 0; --ind){
            for(int buy = 0; buy <= 1; ++buy){
                if(buy){
                    curr[buy] = max(-values[ind] + ahead[0], 0 + ahead[1]);
                }
                else{
                    curr[buy] = max(values[ind] + ahead[1], 0 + ahead[0]);
                }
            }
            ahead = curr;
        }

        return ahead[1];
    }

    int soo(vector<int>& values, int n){
        int aheadBuy = 0, aheadNotBuy = 0, currBuy = 0, currNotBuy = 0;

        for(int ind = n-1; ind >= 0; --ind){
            // buy = 0
            currNotBuy = max(values[ind] + aheadBuy, 0 + aheadNotBuy);

            // buy = 1;
            currBuy = max(-values[ind] + aheadNotBuy, 0 + aheadBuy);

            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }

        return aheadBuy;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        //* Recursive Approach-> TLE
        // return rec(0, 1, n, prices);

        //* DP Memoization->
        // vector<vector<long>> dp(n, vector<long>(2, -1));
        // return rec(0, 1, n, prices, dp);

        //* DP Tabulation->
        // return tab(prices, n);

        //* DP Space Optimisation->
        // return so(prices, n);

        //* DP Space Optimisation using variables->
        return soo(prices, n);
    }
};