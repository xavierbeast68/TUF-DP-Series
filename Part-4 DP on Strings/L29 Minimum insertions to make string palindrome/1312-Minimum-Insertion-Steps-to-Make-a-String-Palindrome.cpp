//* https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
//* https://youtu.be/PF8cW7k8BT8
//* https://www.youtube.com/watch?v=xPBLEj41rFU

class Solution {
public:
    // int lcs(string& s1, string& s2, int m, int n, vector<vector<int>>& memo) {
    //     if (m == 0 || n == 0) {
    //         return 0;
    //     }
    //     if (memo[m][n] != -1) {
    //         return memo[m][n];
    //     }
    //     if (s1[m - 1] == s2[n - 1]) {
    //         return memo[m][n] = 1 + lcs(s1, s2, m - 1, n - 1, memo);
    //     }
    //     return memo[m][n] = max(lcs(s1, s2, m - 1, n, memo), lcs(s1, s2, m, n - 1, memo));
    // }
    // int minInsertions(string s) {
    //     int n = s.length();
    //     string sReverse = s;
    //     reverse(sReverse.begin(), sReverse.end());
    //     vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));

    //     return n - lcs(s, sReverse, n, n, memo);
    // }


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
        string t = s;
        reverse(s.begin(), s.end());

        int n = s.length();
        int m = t.length();

        //* DP Tabulation->
        // return tab(n, m, s, t);

        //* DP Space Optimisation->
        return so(n, m, s, t);
    }
    int minInsertions(string s) {
        return (s.length() - longestPalindromeSubseq(s));
    }


};