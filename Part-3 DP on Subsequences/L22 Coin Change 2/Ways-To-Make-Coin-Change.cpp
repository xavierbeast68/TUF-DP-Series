//* https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//* https://www.youtube.com/watch?v=HgyouUi11zk

#include <bits/stdc++.h>
using namespace std;

long rec(int ind, int target, int num[], vector<vector<long>>& dp){
    if(ind == 0){
        // target == 0 or target is divisble by num[0]
        if(target%num[0] == 0){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(dp[ind][target] != -1){
        return dp[ind][target];
    }

    long notTake = rec(ind-1, target, num, dp);
    long take = 0;

    if(target >= num[ind]){
        take = rec(ind, target-num[ind], num, dp);
    }

    return dp[ind][target] = take + notTake;
}

long tab(int n, int x, int num[]){
    vector<vector<long>> dp(n, vector<long> (x+1, 0));

    // Base Cases->
    for(int target = 0; target <= x; ++target){
        if(target%num[0] == 0){
            dp[0][target] = 1;
        }
    }

    for(int ind = 1; ind < n; ++ind){
        for(int target = 0; target <= x; ++target){
            long notTake = dp[ind-1][target];
            long take = 0;

            if(target >= num[ind]){
                take = dp[ind][target-num[ind]];
            }

            dp[ind][target] = take + notTake;
        }
    }

    return dp[n-1][x];
}

long so(int n, int x, int num[]){
    vector<long> prev(x+1, 0), curr(x+1, 0);

    // Base Cases->
    for(int target = 0; target <= x; ++target){
        if(target%num[0] == 0){
            prev[target] = 1;
        }
    }

    for(int ind = 1; ind < n; ++ind){
        for(int target = 0; target <= x; ++target){
            long notTake = prev[target];
            long take = 0;

            if(target >= num[ind]){
                take = curr[target-num[ind]]; // important step
            }

            curr[target] = take + notTake;
        }
        prev = curr;
    }

    return prev[x];
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here

    //* Recursive Approach-> TLE
    // return rec(n-1, value, denominations);

    //* DP Memoization->
    // vector<vector<long>> dp(n, vector<long>(value+1, -1));
    // return rec(n-1, value, denominations, dp);

    //* DP Tabulation->
    // return tab(n, value, denominations);

    //* DP Space Optimisation->
    return so(n, value, denominations);
}