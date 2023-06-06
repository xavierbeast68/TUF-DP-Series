//* https://www.codingninjas.com/codestudio/problems/highway-billboards_3125969?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//* https://youtu.be/IGIe46xw3YY

#include <bits/stdc++.h> 
using namespace std;

int rec(int ind, int buy, int n, vector<int>& prices, vector<vector<int>>& dp){
    // Base Case
    // end of list
    if(ind >= n){
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
        profit = max(-prices[ind] + rec(ind+1, 0, n, prices, dp),
                        0 + rec(ind+1, 1, n, prices, dp));
    }
    // either sell the boughted stock at current value or skip it
    else{
        // max(soldValue + buyNewStock, notSold + findForNewSellValue)
        profit = max(prices[ind] + rec(ind+2, 1, n, prices, dp),
                        0 + rec(ind+1, 0, n, prices, dp));
    }

    return dp[ind][buy] = profit;
}

int tab(vector<int>& prices, int n){
    vector<vector<int>> dp(n+2, vector<int>(2, 0));

    // dp[n][0] = dp[n][1] = 0;

    for(int ind = n-1; ind >= 0; --ind){
        for(int buy = 0; buy <= 1; ++buy){
            if(buy){
                dp[ind][buy] = max(-prices[ind] + dp[ind+1][0], 
                                    0 + dp[ind+1][1]);
            }
            else{
                dp[ind][buy] = max(prices[ind] + dp[ind+2][1], 
                                    0 + dp[ind+1][0]);
            }
        }
    }

    return dp[0][1];
}

int so(vector<int>& prices, int n){
    vector<int> front1(2, 0), front2(2, 0), curr(2, 0);

    for(int ind = n-1; ind >= 0; --ind){
        for(int buy = 0; buy <= 1; ++buy){
            if(buy){
                curr[buy] = max(-prices[ind] + front1[0], 
                                    0 + front1[1]);
            }
            else{
                curr[buy] = max(prices[ind] + front2[1], 
                                    0 + front1[0]);
            }
        }
        front2 = front1;
        front1 = curr;
    }

    return curr[1];
}

int stockProfit(vector<int> &prices){
    // Write your code here.

    int n = prices.size();

    //* Recursive Approach-> TLE
    // return rec(0, 1, n, prices);

    //* DP Memoization->
    // vector<vector<int>> dp(n, vector<int>(2, -1));
    // return rec(0, 1, n, prices, dp);

    //* DP Tabulation->
    // return tab(prices, n);

    //* DP Space Optimisation->
    return so(prices, n);
}