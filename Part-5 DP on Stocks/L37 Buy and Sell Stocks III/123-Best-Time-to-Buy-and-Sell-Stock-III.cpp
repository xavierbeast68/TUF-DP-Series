//* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
//* https://youtu.be/-uQGzhYj8BQ

class Solution {
public:
    int rec(int ind, int buy, int cap, int n, vector<int>& prices, vector<vector<vector<int>>>& dp){
        // Base Case
        // end of list
        if(ind == n || cap == 0){
            return 0;
        }

        if(dp[ind][buy][cap] != -1){
            return dp[ind][buy][cap];
        }

        int profit = 0;
        // Recursive Case
        // not buyed yet-> either buy current stock or skip it
        if(buy){
            // max(boughtValue + findForSellValue, notBuyed + findForNewBuyValue)
            profit = max(-prices[ind] + rec(ind+1, 0, cap, n, prices, dp),
                            0 + rec(ind+1, 1, cap, n, prices, dp));
        }
        // either sell the boughted stock at current value or skip it
        else{
            // max(soldValue + buyNewStock, notSold + findForNewSellValue)
            profit = max(prices[ind] + rec(ind+1, 1, cap-1, n, prices, dp),
                            0 + rec(ind+1, 0, cap, n, prices, dp));
        }

        return dp[ind][buy][cap] = profit;
    }

    int tab(vector<int>& prices, int n){
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        // Base Cases-> dp[i][j][0] = 0, dp[n][i][j] = 0=> both already covered while declaration

        for(int ind = n-1; ind >= 0; --ind){
            for(int buy = 0; buy <= 1; ++buy){
                for(int cap = 1; cap <= 2; ++cap){
                    // cap = 0 already covered as Base Case

                    if(buy){
                        dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap], 
                                                    0 + dp[ind+1][1][cap]);
                    }
                    else{
                        dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1], 
                                                    0 + dp[ind+1][0][cap]);
                    }

                }
            }
        }

        return dp[0][1][2];
    }

    int so(vector<int>& prices, int n){
        vector<vector<int>> after(2, vector<int>(3, 0)), curr(2, vector<int>(3,0));

        // Base Cases-> already covered while declaration

        for(int ind = n-1; ind >= 0; --ind){
            for(int buy = 0; buy <= 1; ++buy){
                for(int cap = 1; cap <= 2; ++cap){
                    // cap = 0 already covered as Base Case

                    if(buy){
                        curr[buy][cap] = max(-prices[ind] + after[0][cap], 
                                                    0 + after[1][cap]);
                    }
                    else{
                        curr[buy][cap] = max(prices[ind] + after[1][cap-1], 
                                                    0 + after[0][cap]);
                    }

                }
            }
            after = curr;
        }

        return after[1][2];
    }

    //* Another Method
    int newRec(int ind, int trans, int n, vector<int>& prices, vector<vector<int>>& dp){
        if(ind == n || trans == 4){
            return 0;
        }

        if(dp[ind][trans] != -1){
            return dp[ind][trans];
        }

        int profit = 0;
        if(trans%2 == 0){
            profit = max(-prices[ind] + newRec(ind+1, trans+1, n, prices, dp),
                            0 + newRec(ind+1, trans, n, prices, dp));
        }
        else{
            profit = max(prices[ind] + newRec(ind+1, trans+1, n, prices, dp),
                            0 + newRec(ind+1, trans, n, prices, dp));
        }

        return dp[ind][trans] = profit;
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        //* Recursive Approach-> TLE
        // return rec(0, 1, 2, n, prices);

        //* DP Memoization->
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        // return rec(0, 1, 2, n, prices, dp);

        //* DP Tabulation->
        // return tab(prices, n);

        //* DP Space Optimisation->
        // return so(prices, n);

        // Another Method-> Using transaction number instead of capacity
        //* DP Memoization-> 2-D
        vector<vector<int>> dp(n, vector<int> (4,-1));
        return newRec(0, 0, n, prices, dp);
    }
};