//* https://leetcode.com/problems/burst-balloons/
//* https://youtu.be/Yz4LlDSlkns
//* Matrix Chain Multiplication Concept

class Solution
{
public:
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        // Base Case->
        if (i > j){
            return 0;
        }

        if (dp[i][j] != -1){
            return dp[i][j];
        }

        // Recursive Case->
        int maxCoins = INT_MIN;
        for (int ind = i; ind <= j; ind++){
            int coins = (nums[i - 1] * nums[ind] * nums[j + 1]) + f(i, ind - 1, nums, dp) + f(ind + 1, j, nums, dp);
            maxCoins = max(maxCoins, coins);
        }

        return dp[i][j] = maxCoins;
    }

    int tab(vector<int> &nums){
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Base Case-> dp[i][j]=0, for every i>j

        for (int i = n; i >= 1; i--){
            for (int j = 1; j <= n; j++){
                if (i > j){
                    continue;
                }

                int maxCoins = INT_MIN;
                for (int ind = i; ind <= j; ind++){
                    int coins = (nums[i - 1] * nums[ind] * nums[j + 1]) + dp[i][ind - 1] + dp[ind + 1][j];
                    maxCoins = max(maxCoins, coins);
                }

                dp[i][j] = maxCoins;
            }
        }

        return dp[1][n];
    }
    int maxCoins(vector<int> &nums){
        //* Recursive Approach-> TLE
        // int n = nums.size();
        // nums.insert(nums.begin(), 1);
        // nums.push_back(1);
        // return f(1, n, nums);

        //* DP Memoization->
        // int n = nums.size();
        // nums.insert(nums.begin(), 1);
        // nums.push_back(1);
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        // return f(1, n, nums, dp);

        //* DP Tabulation->
        return tab(nums);
    }
};