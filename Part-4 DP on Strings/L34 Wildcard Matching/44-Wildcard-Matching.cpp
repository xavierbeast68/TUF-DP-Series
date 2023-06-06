//* https://leetcode.com/problems/wildcard-matching/
//* https://youtu.be/ZmlQ3vgAOMo

class Solution
{
public:
    // 0-based indexing
    bool rec(int i, int j, string s, string t)
    {
        // Base Cases
        if (i < 0 && j < 0)
        {
            return true;
        }
        if (i < 0 && j >= 0)
        {
            return false;
        }
        if (i >= 0 && j < 0)
        {
            for (int k = 0; k <= i; ++k)
            {
                if (s[k] != '*')
                {
                    return false;
                }
            }
        }

        // Recursive Cases
        if (s[i] == t[j] || s[i] == '?')
        {
            return rec(i - 1, j - 1, s, t);
        }
        else if (s[i] == '*')
        {
            return (rec(i - 1, j, s, t) || rec(i, j - 1, s, t));
        }
        else
        {
            return false;
        }
    }
    // 1-based indexing
    bool f(int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        // Base Cases
        if (i == 0 && j == 0)
        {
            return true;
        }
        if (i == 0 && j > 0)
        {
            return false;
        }
        if (i > 0 && j == 0)
        {
            for (int k = 0; k < i; ++k)
            {
                if (s[k] != '*')
                {
                    return false;
                }
            }
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // Recursive Cases
        if (s[i - 1] == t[j - 1] || s[i - 1] == '?')
        {
            return dp[i][j] = f(i - 1, j - 1, s, t, dp);
        }
        else if (s[i - 1] == '*')
        {
            return dp[i][j] = (f(i - 1, j, s, t, dp) || f(i, j - 1, s, t, dp));
        }
        else
        {
            return dp[i][j] = false;
        }
    }
    bool tab(int n, int m, string s, string t)
    {
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Base Cases->
        dp[0][0] = true;
        for (int j = 1; j <= m; ++j)
            dp[0][j] = false;
        for (int i = 1; i <= n; ++i)
        {
            bool flag = true;
            for (int k = 1; k <= i; ++k)
            {
                if (s[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
            // for every row i, 0th column is initialized
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (s[i - 1] == t[j - 1] || s[i - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (s[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
    bool so(int n, int m, string s, string t)
    {
        vector<bool> prev(m + 1, false), curr(m + 1, false);

        // Base Cases->
        prev[0] = true;
        for (int j = 1; j <= m; ++j)
            prev[j] = false;

        for (int i = 1; i <= n; ++i)
        {

            bool flag = true;
            for (int k = 1; k <= i; ++k)
            {
                if (s[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            // for every row i, 0th column is initialized everytime
            curr[0] = flag;

            for (int j = 1; j <= m; ++j)
            {
                if (s[i - 1] == t[j - 1] || s[i - 1] == '?')
                {
                    curr[j] = prev[j - 1];
                }
                else if (s[i - 1] == '*')
                {
                    curr[j] = prev[j] || curr[j - 1];
                }
                else
                {
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[m];
    }
    bool isMatch(string text, string pattern)
    {
        // pattern-> p
        // text -> s
        int n = pattern.length();
        int m = text.length();

        //* Recursive Approach->
        // 0-based indexing
        // return rec(n-1, m-1, pattern, text);
        // 1-based indexing
        // return f(n, m, pattern, text);

        //* DP Memoization->
        // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        // return f(n, m, pattern, text, dp);

        //* DP Tabulation->
        // return tab(n, m, pattern, text);

        //* DP Space Optimisation->
        return so(n, m, pattern, text);
    }
};