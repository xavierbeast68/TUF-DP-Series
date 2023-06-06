//* https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//* https://www.youtube.com/watch?v=EgG3jsGoPvQ

#include <bits/stdc++.h> 
/*
int rec(int ind, vector<int>& heights){
    if(ind == 0){
        return 0;
    }

    int left = rec(ind-1, heights) + abs(heights[ind]-heights[ind-1]);
    int right = INT_MAX;
    if(ind > 1){
        right = rec(ind-2, heights) + abs(heights[ind]-heights[ind-2]);
    }

    return min(left, right);
}
*/
// int dpMemo(int ind , vector<int>& heights, vector<int>& dp){
//     if(ind == 0){
//         return 0;
//     }
//     if(dp[ind] != -1){
//         return dp[ind];
//     }

//     int left = dpMemo(ind-1, heights, dp) + abs(heights[ind]-heights[ind-1]);
//     int right = INT_MAX;
//     if(ind > 1){
//         right = dpMemo(ind-2, heights, dp) + abs(heights[ind]-heights[ind-2]);
//     }

//     return dp[ind] = min(left, right);
// }
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.

    //* Recursive Solution-> Gives TLE
    // return rec(n-1, heights);

    //* DP(Memoization)
    // vector<int> dp(n+1, -1);
    // return dpMemo(n-1, heights, dp);
    
    //* DP(Tabulation)
    // vector<int> dp(n,0);
    // dp[0] = 0;
    // for(int i = 1; i < n; ++i){
    //     int left = dp[i-1] + abs(heights[i]-heights[i-1]);
        
    //     int right = INT_MAX;
    //     if(i >1){
    //         right = dp[i-2] + abs(heights[i]-heights[i-2]);
    //     }
        
    //     dp[i] = min(left,right);
    // }
    // return dp[n-1];

    //* DP(Tabulation + Space Optimization)->
    int prev1 = 0, prev2 = 0;
    for(int i = 1; i < n; ++i){
        int left = prev1 + abs(heights[i]-heights[i-1]);
        
        int right = INT_MAX;
        if(i >1){
            right = prev2 + abs(heights[i]-heights[i-2]);
        }
        
        prev2 = prev1;
        prev1 = min(left,right);
    }
    return prev1;
}