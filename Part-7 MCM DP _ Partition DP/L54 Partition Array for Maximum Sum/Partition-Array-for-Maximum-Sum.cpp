//* https://www.codingninjas.com/codestudio/problems/maximum-subarray_3755255
//* https://youtu.be/PhWWJmaKfMc

#include <bits/stdc++.h> 
using namespace std;

int f(int i, int n, int k, vector<int>& num, vector<int>& dp){
    // Base Case
    if(i == n){
        return 0;
    }

    if(dp[i] != -1){
        return dp[i];
    }

    int maxSum = INT_MIN;
    int len = 0, maxi = INT_MIN;
    // Recursive Case
    for(int j = i; j < min(i+k, n); j++){
        maxi = max(maxi, num[j]);
        len++;
        int partitionSum = (len*maxi) + f(j+1, n, k, num, dp);

        maxSum = max(maxSum, partitionSum);
    }
    return dp[i] = maxSum;
}

int tab(vector<int>& num, int n, int k){
    vector<int> dp(n+1, 0);

    // Base Case-> dp[n] = 0;

    for(int i = n-1; i >= 0; i--){
        int maxSum = INT_MIN;
        int len = 0, maxi = INT_MIN;
        for(int j = i; j < min(i+k, n); j++){
            maxi = max(maxi, num[j]);
            len++;
            int partitionSum = (len*maxi) + dp[j+1];

            maxSum = max(maxSum, partitionSum);
        }
        dp[i] = maxSum;
    }

    return dp[0];
}

int maximumSubarray(vector<int> &num, int k)
{
    // Write your code here.

    int n = num.size();

    //* Recursive Approach-> TLE
    // return f(0, n, k, num);

    //* DP Memoization->
    // vector<int> dp(n, -1);
    // return f(0, n, k, num, dp);

    //* DP Tabulation->
    return tab(num, n, k);
}