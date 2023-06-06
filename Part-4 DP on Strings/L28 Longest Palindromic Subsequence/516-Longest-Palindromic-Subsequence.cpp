//* https://leetcode.com/problems/longest-palindromic-subsequence/
//* https://youtu.be/6i_T5kkfv4A
//* https://youtu.be/71jPaTBK1dc

class Solution
{
public:
    int tab(int n, int m, string s, string t)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base Cases
        for (int ind2 = 0; ind2 <= m; ++ind2)
            dp[0][ind2] = 0;
        for (int ind1 = 0; ind1 <= n; ++ind1)
            dp[ind1][0] = 0;

        for (int ind1 = 1; ind1 <= n; ++ind1)
        {
            for (int ind2 = 1; ind2 <= m; ++ind2)
            {
                if (s[ind1 - 1] == t[ind2 - 1])
                {
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                }
                else
                {
                    dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
                }
            }
        }

        return dp[n][m];
    }

    int so(int n, int m, string s, string t)
    {
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // Base Cases
        for (int ind2 = 0; ind2 <= m; ++ind2)
            prev[ind2] = 0;

        for (int ind1 = 1; ind1 <= n; ++ind1)
        {
            for (int ind2 = 1; ind2 <= m; ++ind2)
            {
                if (s[ind1 - 1] == t[ind2 - 1])
                {
                    curr[ind2] = 1 + prev[ind2 - 1];
                }
                else
                {
                    curr[ind2] = 0 + max(prev[ind2], curr[ind2 - 1]);
                }
            }
            prev = curr;
        }

        return prev[m];
    }

    int longestPalindromeSubseq(string s)
    {
        // int n = s.size();
        // vector<vector<int>> dp(n, vector<int>(n));
        // for (int i = n - 1; i >= 0; i--) {
        //     dp[i][i] = 1;
        //     for (int j = i + 1; j < n; j++) {
        //         if (s[i] == s[j]) {
        //             dp[i][j] = dp[i + 1][j - 1] + 2;
        //         } else {
        //             dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        //         }
        //     }
        // }
        // return dp[0][n - 1];

        string t = s;
        reverse(s.begin(), s.end());

        int n = s.length();
        int m = t.length();

        //* DP Tabulation->
        // return tab(n, m, s, t);

        //* DP Space Optimisation->
        return so(n, m, s, t);
    }
};