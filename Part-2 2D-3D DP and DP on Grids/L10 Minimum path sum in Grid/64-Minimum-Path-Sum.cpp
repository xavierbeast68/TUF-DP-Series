//* https://leetcode.com/problems/minimum-path-sum/description/
//* https://www.youtube.com/watch?v=_rgTlyky1uQ&ab_channel=takeUforward
//* https://www.youtube.com/watch?v=pGMsrvt0fpk&ab_channel=NeetCode
//* https://www.youtube.com/watch?v=S99RAK_R9rQ&ab_channel=CodeFreaks

class Solution {
public:
    int rec(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row == 0 && col == 0){
            return grid[row][col];
        }
        if(row < 0 || col < 0){
            return 1e9; // or INT_MAX;
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int up = grid[row][col] + rec(row-1, col, grid, dp);
        int left = grid[row][col] + rec(row, col-1, grid, dp);

        return dp[row][col] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {

        // int m=grid.size(), n=grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // dp[0][0]=grid[0][0];
        // for (int i=1; i<m; i++){
        //     dp[i][0]=dp[i-1][0]+grid[i][0];
        // }

        // for (int i=1; i<n; i++){
        //     dp[0][i]=dp[0][i-1]+grid[0][i];
        // }
        
        // for (int i=1; i<m; i++){
        //     for (int j=1; j<n; j++){
        //         dp[i][j]=min(dp[i-1][j], dp[i][j-1])+grid[i][j];
        //     }
        // }
        // return dp[m-1][n-1];

        int m = grid.size();
        int n = grid[0].size();
    
        //* Recursion-> TLE
        // return rec(m-1, n-1, grid);
    
        //* DP Memoization->
        // vector<vector<int>> dp(m, vector<int>(n,-1));
        // return rec(m-1, n-1, grid, dp);
    
        //* DP Tabulation->
        // int dp[m][n];
        // for(int i = 0; i < m; ++i){
        //     for(int j = 0; j < n; ++j){
        //         if(i == 0 && j == 0){
        //             dp[i][j] = grid[i][j];
        //         }
        //         else{
        //             int up , left;
        //             up = left = grid[i][j];
                    
        //             if(i > 0){
        //                 up += dp[i-1][j];
        //             }
        //             else{
        //                 up = 1e9;
        //             }
    
        //             if(j > 0){
        //                 left += dp[i][j-1];
        //             }
        //             else{
        //                 left = 1e9;
        //             }
    
        //             dp[i][j] = min(up, left);
        //         }
        //     }
        // }
        // return dp[m-1][n-1];
    
    
        //* DP (Tabulation + Space Optimisation)->
        vector<int> prev(n, 0);
        for(int i = 0; i < m; ++i){
            vector<int> curr(n, 0);
            for(int j = 0; j < n; ++j){
                if(i == 0 && j == 0){
                    curr[j] = grid[i][j];
                }
                else{
                    int up , left;
                    up = left = grid[i][j];
                    
                    if(i > 0){
                        up += prev[j];
                    }
                    else{
                        up = 1e9;
                    }
    
                    if(j > 0){
                        left += curr[j-1];
                    }
                    else{
                        left = 1e9;
                    }
    
                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};