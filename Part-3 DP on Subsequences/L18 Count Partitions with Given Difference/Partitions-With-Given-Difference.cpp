//* https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//* https://www.youtube.com/watch?v=zoilQD1kYSg


#include <bits/stdc++.h> 
using namespace std;

int mod =(int)1e9+7;

int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){

    if(ind == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = countPartitionsUtil(ind-1,target,arr, dp);
    int taken = 0;
    if(arr[ind]<=target)
        taken = countPartitionsUtil(ind-1,target-arr[ind],arr, dp);
        
    return dp[ind][target] = (notTaken + taken)%mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.

    int totSum = 0;
    for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-d<0) return 0;
    if((totSum-d)%2==1) return 0;
    
    int s2 = (totSum-d)/2;
    
    //* Recursive Approach-> TLE
    // return countPartitionsUtil(n-1,s2,arr);

    //* DP Memoization
    // vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    // return countPartitionsUtil(n-1,s2,arr, dp);

    //* DP Tabulation->
    // vector<vector<int>> dp(n,vector<int>(s2+1, 0));
    // if(arr[0] == 0){
    //     dp[0][0] = 2;
    // }
    // else{
    //     dp[0][0] = 1;
    // }
    // if(arr[0] != 0 && arr[0] <= s2){
    //     dp[0][arr[0]] = 1;
    // }
    // for(int ind = 1; ind < n; ++ind){
    //     for(int target = 0; target <= s2; ++target){
    //         int notTaken = dp[ind-1][target];
    //         int taken = 0;
    //         if(arr[ind]<=target)
    //             taken = dp[ind-1][target-arr[ind]];

    //         dp[ind][target] = (notTaken + taken)%mod;
    //     }
    // }
    // return dp[n-1][s2];


    //* DP Space Optimisation->
    vector<int> prev(s2+1, 0), curr(s2+1, 0);
    if(arr[0] == 0){
        prev[0] = 2;
    }
    else{
        prev[0] = 1;
    }
    if(arr[0] != 0 && arr[0] <= s2){
        prev[arr[0]] = 1;
    }
    for(int ind = 1; ind < n; ++ind){
        for(int target = 0; target <= s2; ++target){
            int notTaken = prev[target];
            int taken = 0;
            if(arr[ind]<=target)
                taken = prev[target-arr[ind]];

            curr[target] = (notTaken + taken)%mod;
        }
        prev = curr;
    }
    return prev[s2];
}