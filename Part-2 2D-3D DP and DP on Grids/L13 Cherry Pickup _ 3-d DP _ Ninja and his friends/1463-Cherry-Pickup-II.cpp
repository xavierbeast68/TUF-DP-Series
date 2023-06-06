//* https://leetcode.com/problems/cherry-pickup-ii/description/
//* https://youtu.be/QGfn7JeXK54

class Solution {
public:
    int rec(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        // base case-> out of Boundary
        if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()){
            return -1e8;
        }
        // terminating condition->
        if(i == grid.size()-1){
            if(j1 == j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }

        if(dp[i][j1][j2] != -1){
            return dp[i][j1][j2];
        }

        int maxi = -1e8;
        int value;
        if(j1 == j2){
            value = grid[i][j1];
        }
        else{
            value = grid[i][j1] + grid[i][j2];
        }
        for(int dj1 = -1; dj1 <= 1; ++dj1){
            for(int dj2 = -1; dj2 <= 1; ++dj2){
                maxi = max(maxi, value + rec(i+1, j1+dj1, j2+dj2, grid, dp));
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //* Recursion-> TLE
        // return rec(0, 0, m-1, grid);   // (startingRow, AlicePlace, BobPlace, grid)

        //* DP Memoization->
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        // return rec(0, 0, m-1, grid, dp);

        //* DP Tabulation->
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        // // Base Case->
        // for(int j1 = 0; j1 < m; ++j1){
        //     for(int j2 = 0; j2 < m; ++j2){
        //         if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
        //         else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        //     }
        // }
        // for(int i = n-2; i >= 0; --i){
        //     for(int j1 = 0; j1 < m; ++j1){
        //         for(int j2 = 0; j2 < m; ++j2){
        //             int maxi = -1e8;
        //             for(int dj1 = -1; dj1 <= 1; ++dj1){
        //                 for(int dj2 = -1; dj2 <= 1; ++dj2){
        //                     int value; // current element value
        //                     if(j1 == j2){
        //                         value = grid[i][j1];
        //                     }
        //                     else{
        //                         value = grid[i][j1] + grid[i][j2];
        //                     }

        //                     if(j1+dj1 < 0 || j1+dj1 >= m || j2+dj2 < 0 || j2+dj2 >= m){
        //                         value = -1e8;
        //                     }
        //                     else{
        //                         value += dp[i+1][j1+dj1][j2+dj2];
        //                     }

        //                     maxi = max(maxi, value);
        //                 }
        //             }
        //             dp[i][j1][j2] = maxi;
        //         }
        //     }
        // }
        // return dp[0][0][m-1];


        //* DP (Tabulation + Space Optimisation)->
        vector<vector<int>> front(m, vector<int>(m, -1)), curr(m, vector<int>(m, -1));
        // Base Case->
        for(int j1 = 0; j1 < m; ++j1){
            for(int j2 = 0; j2 < m; ++j2){
                if(j1 == j2) front[j1][j2] = grid[n-1][j1];
                else front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        for(int i = n-2; i >= 0; --i){
            for(int j1 = 0; j1 < m; ++j1){
                for(int j2 = 0; j2 < m; ++j2){
                    curr[j1][j2] = -1e8;
                    for(int dj1 = -1; dj1 <= 1; ++dj1){
                        for(int dj2 = -1; dj2 <= 1; ++dj2){
                            int value; // current element value
                            if(j1 == j2){
                                value = grid[i][j1];
                            }
                            else{
                                value = grid[i][j1] + grid[i][j2];
                            }

                            if(j1+dj1 < 0 || j1+dj1 >= m || j2+dj2 < 0 || j2+dj2 >= m){
                                value = -1e8;
                            }
                            else{
                                value += front[j1+dj1][j2+dj2];
                            }

                            curr[j1][j2] = max(curr[j1][j2], value);
                        }
                    }
                }
            }
            front = curr;
        }
        return front[0][m-1];
    }
};