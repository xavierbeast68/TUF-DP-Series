//* https://leetcode.com/problems/partition-equal-subset-sum/
//* https://www.youtube.com/watch?v=7win3dcgo3k
//* https://www.youtube.com/watch?v=fWX9xDmIzRI (Pre-Requisite-> Subset Sum Equal to K)

class Solution
{
public:
    bool rec(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
        {
            return true;
        }
        if (ind == 0)
        {
            return arr[0] == target;
        }

        if (dp[ind][target] != -1)
        {
            return dp[ind][target];
        }

        bool notTake = rec(ind - 1, target, arr, dp);
        bool take = false;

        if (target >= arr[ind])
        {
            take = rec(ind - 1, target - arr[ind], arr, dp);
        }

        return dp[ind][target] = (take || notTake);
    }

    bool canPartition(vector<int> &nums)
    {
        int totalSum = accumulate(begin(nums), end(nums), 0);
        // if totalSum is Odd, then array can't be partitioned into two subsets with equal sum
        if (totalSum % 2 == 1)
        {
            return false;
        }
        // totalSum is even
        int k = totalSum / 2; // target
        int n = nums.size();

        // Finding Subset Sum Equal to K

        //* DP Memoization
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return rec(n - 1, k, nums, dp);

        //* DP (Tabulation + Space Optimisation)
        vector<bool> prev(k + 1, 0);
        // Base Case
        // 1) target == 0 (irrespective of value of ind)
        prev[0] = true;
        // 2) if ind == 0, target == nums[0];
        if (k >= nums[0])
            prev[nums[0]] = true;
        // Recurrence->
        // ind = 0, only at target = nums[0] remains true,others false
        for (int ind = 1; ind < n; ++ind)
        {
            vector<bool> curr(k + 1, 0);
            curr[0] = true; // for target == 0, always true
            // target = 0 already filled as true
            for (int target = 1; target <= k; ++target)
            {
                bool notTake = prev[target];

                bool take = false;

                if (target >= nums[ind])
                {
                    take = prev[target - nums[ind]];
                }

                curr[target] = (take | notTake);
            }
            prev = curr;
        }
        return prev[k];
    }
};