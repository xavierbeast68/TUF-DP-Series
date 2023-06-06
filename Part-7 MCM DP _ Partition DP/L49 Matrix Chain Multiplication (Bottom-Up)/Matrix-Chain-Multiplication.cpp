//* https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//* https://youtu.be/vRVfmbCFW7Y
//* https://youtu.be/pDCXsbAw5Cg

#include <bits/stdc++.h> 
using namespace std;

int f(int i, int j, vector<int>& arr, vector<vector<int>>& dp){
    // Base Case->
    if(i == j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    // Recursive Case->
    int minCost = 1e9;
    for(int k = i; k < j; k++){
        int steps = (arr[i-1] * arr[k] * arr[j]) + f(i, k, arr, dp) + f(k+1, j, arr, dp);
        minCost = min(minCost, steps);
    }
    return dp[i][j] = minCost;
}

int tab(vector<int>& arr, int n){
    vector<vector<int>> dp(n, vector<int> (n, 0));

    // Base Case-> dp[i][i] = 0, for every i from 1 to n

    for(int i = n-1; i >= 1; i--){
        for(int j = i+1; j < n; j++){
            int minCost = 1e9;

            for(int k = i; k < j; k++){
                int steps = (arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];
                minCost = min(minCost, steps);
            }
            dp[i][j] = minCost;
        }
    }

    return dp[1][n-1];
}

int matrixMultiplication(vector<int> &arr, int n)
{
    // Write your code here.

    //* Recursive Approach-> TLE
    // return f(1, n-1, arr);

    //* DP Memoization->
    // vector<vector<int>> dp(n, vector<int> (n, -1));
    // return f(1, n-1, arr, dp);

    //* DP Tabulation->
    return tab(arr, n);
}