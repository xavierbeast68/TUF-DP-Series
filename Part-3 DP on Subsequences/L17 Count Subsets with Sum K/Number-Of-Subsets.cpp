//* https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//* https://www.youtube.com/watch?v=ZHyb-A2Mte4
//* https://www.youtube.com/watch?v=zoilQD1kYSg

#include <bits/stdc++.h> 

int rec(int ind, int sum, vector<int>& num, vector<vector<int>>& dp){
    // edge cases for num[ind]==0 and sum==0
    if(ind == 0){
        if(sum == 0 && num[0] == 0) return 2; // take = 1, notTake = 1
        if(sum==0 || num[0] == sum) return 1;
        else return 0;
    }

    if(dp[ind][sum] != -1){
        return dp[ind][sum];
    }

    int notTake = rec(ind-1, sum, num, dp);
    int take = 0;
    if(num[ind] <= sum){
        take = rec(ind-1, sum-num[ind], num, dp);
    }

    return dp[ind][sum] = take + notTake;
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.

    int n = num.size();

    //* Recursive Approach-> TLE
    // return rec(n-1, tar, num);

    //* DP Memoization->
    // vector<vector<int>> dp(n, vector<int> (tar+1, -1));
    // return rec(n-1, tar, num, dp);

    //* DP Tabulation-> (also handles the cases where num[i] == 0)
    // vector<vector<int>> dp(n, vector<int> (tar+1, 0));

    // // edge cases for num[ind]==0 and sum==0
    // // when target == 0
    // // at ind == 0 -> few cases arise->
    // if(num[0] == 0){
    //     // take = 1, notTake = 1
    //     dp[0][0] = 2;
    // } else{
    //     // take = 0, notTake = 1
    //     dp[0][0] = 1;
    // }
    // if(num[0]!= 0 && num[0] <= tar){
    //     dp[0][num[0]] = 1;
    // }

    // for(int ind = 1; ind < n; ++ind){
    //     for(int sum = 0; sum <= tar; ++sum){
            
    //         int notTake = dp[ind-1][sum];
    //         int take = 0;
    //         if(num[ind] <= sum){
    //             take = dp[ind-1][sum-num[ind]];
    //         }

    //         dp[ind][sum] = take + notTake;
    //     }
    // }
    // return dp[n-1][tar];


    //* DP Space Optimisation->
    vector<int> prev(tar+1, 0), curr(tar+1, 0);
    if(num[0] == 0){
        // take = 1, notTake = 1
        prev[0] = 2;
    } else{
        // take = 0, notTake = 1
        prev[0] = 1;
    }
    if(num[0]!= 0 && num[0] <= tar){
        prev[num[0]] = 1;
    }

    for(int ind = 1; ind < n; ++ind){
        for(int sum = 0; sum <= tar; ++sum){
            
            int notTake = prev[sum];
            int take = 0;
            if(num[ind] <= sum){
                take = prev[sum-num[ind]];
            }

            curr[sum] = take + notTake;
        }
        prev = curr;
    }
    return prev[tar];
}