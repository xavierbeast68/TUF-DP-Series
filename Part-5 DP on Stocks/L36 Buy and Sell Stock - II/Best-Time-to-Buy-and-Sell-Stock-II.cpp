//* https://www.codingninjas.com/codestudio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//* https://youtu.be/nGJmxkUJQGs

#include <bits/stdc++.h>
using namespace std;

long rec(int ind, int buy, int n, long *values, vector<vector<long>>& dp){
    // Base Case
    // end of list
    if(ind == n){
        return 0;
    }

    if(dp[ind][buy] != -1){
        return dp[ind][buy];
    }

    long profit = 0;
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

long tab(long *values, int n){
    vector<vector<long>> dp(n+1, vector<long>(2, 0));

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

long so(long *values, int n){
    vector<long> ahead(2, 0), curr(2, 0);

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

long soo(long *values, int n){
    long aheadBuy = 0, aheadNotBuy = 0, currBuy = 0, currNotBuy = 0;

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

long getMaximumProfit(long *values, int n)
{
    //Write your code here

    //* Recursive Approach-> TLE
    // return rec(0, 1, n, values);

    //* DP Memoization->
    // vector<vector<long>> dp(n, vector<long>(2, -1));
    // return rec(0, 1, n, values, dp);

    //* DP Tabulation->
    // return tab(values, n);

    //* DP Space Optimisation->
    // return so(values, n);

    //* DP Space Optimisation using variables->
    return soo(values, n);
}