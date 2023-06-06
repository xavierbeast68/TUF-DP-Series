//* https://leetcode.com/problems/shortest-common-supersequence/
//* https://youtu.be/xElxAuBcvsU

class Solution
{
public:
    string tab(int n, int m, string s, string t)
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

        // Making answer string using the dp table
        string ans = "";
        int i = n, j = m;
        while (i > 0 && j > 0)
        {
            if (s[i - 1] == t[j - 1])
            {
                ans += s[i - 1];
                i--, j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += s[i - 1]; // moving up
                i--;
            }
            else
            {
                ans += t[j - 1]; // moving left;
                j--;
            }
        }
        // adding remaining characters
        while (i > 0)
        {
            ans += s[i - 1];
            i--;
        }
        while (j > 0)
        {
            ans += t[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    string longestCommonSubsequence(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        //* DP Tabulation->
        return tab(n, m, s, t);
    }
    string shortestCommonSupersequence(string str1, string str2)
    {
        return longestCommonSubsequence(str1, str2);
    }
};