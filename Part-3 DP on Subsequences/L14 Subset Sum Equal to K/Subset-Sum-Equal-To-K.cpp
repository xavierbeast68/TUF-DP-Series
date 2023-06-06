//* https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1
//* https://www.youtube.com/watch?v=fWX9xDmIzRI

#include <bits/stdc++.h> 

bool rec(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
    if(target == 0){
        return true;
    }
    if(ind == 0){
        return arr[0] == target;
    }

    if(dp[ind][target] != -1){
        return dp[ind][target];
    }

    bool notTake = rec(ind-1, target, arr, dp);
    bool take = false;

    if(target >= arr[ind]){
        take = rec(ind-1, target-arr[ind], arr, dp);
    }

    return dp[ind][target] = (take || notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.

    //* Recursive Approach-> TLE
    // return rec(n-1, k, arr);

    //* DP Memoization->
    // vector<vector<int>> dp(n, vector<int> (k+1, -1));
    // return rec(n-1, k, arr, dp);

    //* DP Tabulation->
    // vector<vector<bool>> dp(n, vector<bool> (k+1, 0));
    // // Base Case
    // //1) target == 0 (irrespective of value of ind)
    // for(int ind = 0; ind < n; ++ind){
    //     dp[ind][0] = true;
    // }
    // //2) if ind == 0, target == arr[0];
    // if(arr[0] <= k) dp[0][arr[0]] = true;
    // // Recurrence->
    // // ind = 0, only at target = arr[0] remains true,others false
    // for(int ind = 1; ind < n; ++ind){
    //     // target = 0 already filled as true
    //     for(int target = 1; target <= k; ++target){
    //         bool notTake = dp[ind-1][target];

    //         bool take = false;

    //         if(target >= arr[ind]){
    //             take = dp[ind-1][target-arr[ind]];
    //         }

    //         dp[ind][target] = (take | notTake);
    //     }
    // }
    // return dp[n-1][k];


    //* DP Tabulation + Space Optimisation->
    vector<bool> prev(k+1, 0);
    // Base Case
    //1) target == 0 (irrespective of value of ind)
    prev[0] = true;
    //2) if ind == 0, target == arr[0];
    if(arr[0] <= k) prev[arr[0]] = true;
    // Recurrence->
    // ind = 0, only at target = arr[0] remains true,others false
    for(int ind = 1; ind < n; ++ind){
        vector<bool> curr(k+1, 0);
        curr[0] = true; // for target == 0, always true
        // target = 0 already filled as true
        for(int target = 1; target <= k; ++target){
            bool notTake = prev[target];

            bool take = false;

            if(target >= arr[ind]){
                take = prev[target-arr[ind]];
            }

            curr[target] = (take | notTake);
        }
        prev = curr;
    }
    return prev[k];
}