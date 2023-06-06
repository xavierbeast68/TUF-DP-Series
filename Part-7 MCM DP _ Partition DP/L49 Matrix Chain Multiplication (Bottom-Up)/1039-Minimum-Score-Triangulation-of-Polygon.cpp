//* https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/
//* https://youtu.be/vRVfmbCFW7Y
//* https://youtu.be/pDCXsbAw5Cg
//! MCM (Matrix Chain Multiplication Concept)

class Solution {
public:
    int f(int i, int j, vector<int>& values, vector<vector<int>>& dp){
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
            int steps = (values[i-1] * values[k] * values[j]) + f(i, k, values, dp) + f(k+1, j, values, dp);
            minCost = min(minCost, steps);
        }
        return dp[i][j] = minCost;
    }

    int tab(vector<int>& values, int n){
        vector<vector<int>> dp(n, vector<int> (n, 0));

        // Base Case-> dp[i][i] = 0, for every i from 1 to n

        for(int i = n-1; i >= 1; i--){
            for(int j = i+1; j < n; j++){
                int minCost = 1e9;

                for(int k = i; k < j; k++){
                    int steps = (values[i-1] * values[k] * values[j]) + dp[i][k] + dp[k+1][j];
                    minCost = min(minCost, steps);
                }
                dp[i][j] = minCost;
            }
        }

        return dp[1][n-1];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        //* Recursive Approach-> TLE
        // return f(1, n-1, values);

        //* DP Memoization->
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        // return f(1, n-1, values, dp);

        //* DP Tabulation->
        return tab(values, n);
    }
};