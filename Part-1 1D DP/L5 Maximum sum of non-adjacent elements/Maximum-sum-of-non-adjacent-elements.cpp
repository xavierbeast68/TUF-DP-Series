//* https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
int maxSum(int ind, vector<int>& nums, vector<int>& dp){
    if(ind == 0){
        return nums[0];
    }
    if(ind < 0){
        return 0;
    }

    if(dp[ind] != -1){
        return dp[ind];
    }

    int take = nums[ind] + maxSum(ind-2, nums, dp);
    int notTake = 0 + maxSum(ind-1, nums, dp);

    return dp[ind] = max(take, notTake);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

    //* Recursive Approach->
    // return maxSum(nums.size()-1, nums);

    //* DP(Memoization)
    // vector<int> dp(nums.size(), -1);
    // return maxSum(nums.size()-1, nums, dp);

    //* DP(Tabulation)
    // vector<int> dp(nums.size(), 0);
    // dp[0] = nums[0];
    // for(int i = 1; i < nums.size(); ++i){
    //     int take = nums[i];
    //     if(i > 1){
    //         take += dp[i-2];
    //     }

    //     int notTake = 0 + dp[i-1];

    //     dp[i] = max(take, notTake);
    // }
    // return dp[nums.size()-1];

    //* DP(Tabulation + Space Optimisation)->
    int prev1 = nums[0], prev2 = 0;
    for(int i = 1; i < nums.size(); ++i){
        int take = nums[i];
        if(i > 1){
            take += prev2;
        }

        int notTake = 0 + prev1;

        prev2 = prev1;
        prev1 = max(take, notTake);
    }
    return prev1;
}