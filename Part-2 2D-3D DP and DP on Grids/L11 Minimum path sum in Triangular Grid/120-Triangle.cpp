//* https://leetcode.com/problems/triangle/
//* https://youtu.be/SrP-PiLSYC0

class Solution
{
public:
    int rec(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (i == n - 1)
        {
            return triangle[i][j];
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int down = triangle[i][j] + rec(i + 1, j, n, triangle, dp);
        int diagonal = triangle[i][j] + rec(i + 1, j + 1, n, triangle, dp);

        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();

        //* Recursive Approach-> TLE
        // return rec(0, 0, n, triangle);

        //* DP Memoization->
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return rec(0, 0, n, triangle, dp);

        //* DP Tabulation->
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        // // base cases->
        // for (int j = 0; j < n; j++)
        // {
        //     dp[n - 1][j] = triangle[n - 1][j];
        // }
        // for (int i = n - 2; i >= 0; i--)
        // {
        //     for (int j = i; j >= 0; j--)
        //     {
        //         int down = triangle[i][j] + dp[i + 1][j];
        //         int diagonal = triangle[i][j] + dp[i + 1][j + 1];

        //         dp[i][j] = min(down, diagonal);
        //     }
        // }
        // return dp[0][0];

        //* DP (Tabulation + Space Optimization)->
        vector<int> prev(n);
        // base cases->
        for (int j = 0; j < n; j++)
        {
            prev[j] = triangle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> curr(n);
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + prev[j];
                int diagonal = triangle[i][j] + prev[j + 1];

                curr[j] = min(down, diagonal);
            }
            prev = curr;
        }
        return prev[0];
    }
};