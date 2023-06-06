//* https://leetcode.com/problems/minimum-falling-path-sum/
//* https://youtu.be/N_aJ5qQbYA0

class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(j < 0 || j >= matrix[0].size()){
            return 1e9;
        }
        if(i == 0){
            return matrix[0][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int u = matrix[i][j] + rec(i-1, j, matrix, dp);
        int ld = matrix[i][j] + rec(i-1, j-1, matrix, dp);
        int rd = matrix[i][j] + rec(i-1, j+1, matrix, dp);

        return dp[i][j] = min(u, min(ld, rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //  Write your code here.

        int n = matrix.size();
        int m = matrix[0].size();
        //* Recursive Approach-> TLE
        // int mini = 1e9;
        // for(int j = 0; j < m; j++){
        //     mini = min(mini, rec(n-1, j, matrix));
        // }
        // return mini;

        //* DP Memoization->
        // vector<vector<int>> dp(n, vector<int>(m,-1));
        // int mini = 1e9;
        // for(int j = 0; j < m; j++){
        //     mini = min(mini, rec(n-1, j, matrix, dp));
        // }
        // return mini;


        //* DP Tabulation->
        // vector<vector<int>> dp(n, vector<int> (m,0));
        // // base cases->
        // for(int j = 0; j < m; j++){
        //     dp[0][j] = matrix[0][j];
        // }
        // for(int i = 1; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         int u = matrix[i][j] + dp[i-1][j];

        //         int ld = matrix[i][j];
        //         if(j > 0){
        //             ld += dp[i-1][j-1];
        //         }
        //         else{
        //             ld += 1e9;
        //         }

        //         int rd = matrix[i][j];
        //         if(j+1 < m){
        //             rd += dp[i-1][j+1];
        //         }
        //         else{
        //             rd += e19;
        //         }

        //         dp[i][j] = min(u, min(ld, rd));
        //     }
        // }
        // int mini = 1e9;
        // for(int j = 0; j < m; j++){
        //     mini = min(mini, dp[n-1][j]);
        // }
        // return mini;

        //* DP (Tabulation + Space Optimisation)->
        vector<int> prev(m);
        // base cases->
        for(int j = 0; j < m; j++){
            prev[j] = matrix[0][j];
        }
        for(int i = 1; i < n; i++){
            vector<int> curr(m);
            for(int j = 0; j < m; j++){
                int u = matrix[i][j] + prev[j];

                int ld = matrix[i][j];
                if(j > 0){
                    ld += prev[j-1];
                }
                else{
                    ld += 1e9;
                }

                int rd = matrix[i][j];
                if(j+1 < m){
                    rd += prev[j+1];
                }
                else{
                    rd += 1e9;
                }

                curr[j] = min(u, min(ld, rd));
            }
            prev = curr;
        }
        int mini = 1e9;
        for(int j = 0; j < m; j++){
            mini = min(mini, prev[j]);
        }
        return mini;
    }
};