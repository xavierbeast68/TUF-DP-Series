//* https://leetcode.com/problems/unique-paths-ii/
//* https://youtu.be/TmhpgXScLyY

class Solution
{
public:
    int rec(int row, int col, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        if (row >= 0 && col >= 0 && obstacleGrid[row][col] == 1)
        {
            return 0;
        }
        if (row == 0 && col == 0)
        {
            return 1;
        }
        if (row < 0 || col < 0)
        {
            return 0;
        }

        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }

        int up = rec(row - 1, col, obstacleGrid, dp);
        int left = rec(row, col - 1, obstacleGrid, dp);
        return dp[row][col] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        //* Recrusive Soln-> TLE
        // return rec(m - 1, n - 1, obstacleGrid);

        //* DP Memoization->
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return rec(m - 1, n - 1, obstacleGrid, dp);

        //* DP Tabulation->
        // int dp[m][n];
        // for (int i = 0; i < m; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //     {
        //         if (obstacleGrid[i][j] == 1)
        //         {
        //             dp[i][j] = 0;
        //         }
        //         else if (i == 0 && j == 0)
        //         {
        //             dp[i][j] = 1;
        //         }
        //         else
        //         {
        //             int up = 0, left = 0;
        //             if (i > 0)
        //             {
        //                 up = dp[i - 1][j];
        //             }
        //             if (j > 0)
        //             {
        //                 left = dp[i][j - 1];
        //             }

        //             dp[i][j] = up + left;
        //         }
        //     }
        // }
        // return dp[m - 1][n - 1];

        //* DP (Tabulation + Space Optimisation)
        vector<int> prev(n, 0);
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    temp[j] = 0;
                }
                else if (i == 0 && j == 0)
                {
                    temp[j] = 1;
                }
                else
                {

                    int up = 0, left = 0;
                    if (i > 0)
                    {
                        up = prev[j];
                    }
                    if (j > 0)
                    {
                        left = temp[j - 1];
                    }

                    temp[j] = up + left;
                }
            }
            prev = temp;
        }
        return prev[n - 1];
    }
};