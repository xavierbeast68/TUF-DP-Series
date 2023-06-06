//* https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
//* https://youtu.be/_wP9mWNPL5w

class Solution
{
public:
    int tab(int n, int m, vector<int> &s, vector<int> &t)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;

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
                    ans = max(ans, dp[ind1][ind2]);
                }
                else
                {
                    dp[ind1][ind2] = 0;
                }
            }
        }

        return ans;
    }

    int so(int n, int m, vector<int> &s, vector<int> &t)
    {
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        int ans = 0;

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
                    ans = max(ans, curr[ind2]);
                }
                else
                {
                    curr[ind2] = 0;
                }
            }
            prev = curr;
        }

        return ans;
    }
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        //* DP Tabulation->
        // return tab(n, m, nums1, nums2);

        //* DP Space Optimisation->
        return so(n, m, nums1, nums2);
    }
};