//* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
//* https://youtu.be/IV1dHbk5CDc

class Solution {
public:

    int so(vector<int>& prices, int n, int k){
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

    int newRec(int ind, int trans, int n, int k, vector<int>& prices, vector<vector<int>>& dp){
        if(ind == n || trans == 2*k){
            return 0;
        }

        if(dp[ind][trans] != -1){
            return dp[ind][trans];
        }

        int profit = 0;
        if(trans%2 == 0){
            profit = max(-prices[ind] + newRec(ind+1, trans+1, n, k, prices, dp),
                            0 + newRec(ind+1, trans, n, k, prices, dp));
        }
        else{
            profit = max(prices[ind] + newRec(ind+1, trans+1, n, k, prices, dp),
                            0 + newRec(ind+1, trans, n, k, prices, dp));
        }

        return dp[ind][trans] = profit;
    }

    int tab(int n, int k, vector<int>& prices){
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

        for(int ind = n-1; ind >= 0; --ind){
            for(int trans = 2*k-1; trans >= 0; --trans){
                int profit = 0;
                if(trans%2 == 0){
                    profit = max(-prices[ind] + dp[ind+1][trans+1],
                                    0 + dp[ind+1][trans]);
                }
                else{
                    profit = max(prices[ind] + dp[ind+1][trans+1],
                                    0 + dp[ind+1][trans]);
                }

                dp[ind][trans] = profit;
            }
        }

        return dp[0][0];
    }

    int soo(int n, int k, vector<int>& prices){
        vector<int> after(2*k+1, 0), curr(2*k+1, 0);

        for(int ind = n-1; ind >= 0; --ind){
            for(int trans = 2*k-1; trans >= 0; --trans){
                int profit = 0;
                if(trans%2 == 0){
                    profit = max(-prices[ind] + after[trans+1],
                                    0 + after[trans]);
                }
                else{
                    profit = max(prices[ind] + after[trans+1],
                                    0 + after[trans]);
                }

                curr[trans] = profit;
            }
            after = curr;
        }

        return after[0];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        //* DP Space Optimisation (Buy and Sell Stock -III)->
        // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/945630643/
        // return so(prices, n, k);

        // Another Method-> Using transaction number instead of capacity
        //* DP Memoization-> 2-D
        // vector<vector<int>> dp(n, vector<int> (2*k,-1));
        // return newRec(0, 0, n, k, prices, dp);

        //* DP Tabulation->
        // return tab(n, k, prices);

        //* DP Space Optimisation->
        return soo(n, k, prices);
    }
};