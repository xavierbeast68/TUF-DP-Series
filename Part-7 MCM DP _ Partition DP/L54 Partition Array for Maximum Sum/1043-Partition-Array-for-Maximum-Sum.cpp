//* https://leetcode.com/problems/partition-array-for-maximum-sum/
//* https://youtu.be/PhWWJmaKfMc

class Solution {
public:
    int f(int i, int n, int k, vector<int>& arr, vector<int>& dp){
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
            maxi = max(maxi, arr[j]);
            len++;
            int partitionSum = (len*maxi) + f(j+1, n, k, arr, dp);

            maxSum = max(maxSum, partitionSum);
        }
        return dp[i] = maxSum;
    }

    int tab(vector<int>& arr, int n, int k){
        vector<int> dp(n+1, 0);

        // Base Case-> dp[n] = 0;

        for(int i = n-1; i >= 0; i--){
            int maxSum = INT_MIN;
            int len = 0, maxi = INT_MIN;
            for(int j = i; j < min(i+k, n); j++){
                maxi = max(maxi, arr[j]);
                len++;
                int partitionSum = (len*maxi) + dp[j+1];

                maxSum = max(maxSum, partitionSum);
            }
            dp[i] = maxSum;
        }

        return dp[0];
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        //* Recursive Approach-> TLE
        // return f(0, n, k, arr);

        //* DP Memoization->
        // vector<int> dp(n, -1);
        // return f(0, n, k, arr, dp);

        //* DP Tabulation->
        return tab(arr, n, k);
    }
};