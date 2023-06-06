//* https://leetcode.com/problems/longest-increasing-subsequence/description/
//* https://youtu.be/ekcwMsSIzVc

class Solution {
public:
    int rec(int ind, int prev_ind, int n, vector<int>& nums){
        // Base Case
        if(ind == n){
            return 0;
        }

        // not take case
        int len = 0 + rec(ind+1, prev_ind, n, nums);
        // take case
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            len = max(len, 1 + rec(ind+1, ind, n, nums));
        }

        return len;
    }

    int f(int ind, int prev_ind, int n, vector<int>& nums, vector<vector<int>>& dp){
        // Base Case
        if(ind == n){
            return 0;
        }

        if(dp[ind][prev_ind + 1] != -1){
            return dp[ind][prev_ind + 1];
        }

        // not take case
        int len = 0 + f(ind+1, prev_ind, n, nums, dp);
        // take case
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            len = max(len, 1 + f(ind+1, ind, n, nums, dp));
        }

        return dp[ind][prev_ind + 1] = len;
    }

    
    int tab(int n, vector<int>& nums){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int ind = n-1; ind >= 0; --ind){
            for(int prev_ind = ind-1; prev_ind >= -1; --prev_ind){
                int len = 0 + dp[ind+1][prev_ind+1];

                if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
                    len = max(len, 1 + dp[ind+1][ind+1]);
                }

                dp[ind][prev_ind+1] = len;
            }
        }

        return dp[0][0]; // dp[0][-1+1]
    }

    int so(int n, vector<int>& nums){
        vector<int> next(n+1, 0), curr(n+1, 0);

        for(int ind = n-1; ind >= 0; --ind){
            for(int prev_ind = ind-1; prev_ind >= -1; --prev_ind){
                int len = 0 + next[prev_ind+1];

                if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
                    len = max(len, 1 + next[ind+1]);
                }

                curr[prev_ind+1] = len;
            }
            next = curr;
        }

        return next[0]; // next[-1+1]
    }

    int soo(int n, vector<int>& nums){
        vector<int> dp(n, 1);
        int maxi = 1;

        for(int ind = 0; ind < n; ++ind){
            for(int prev_ind = 0; prev_ind < ind; ++prev_ind){
                if(nums[prev_ind] < nums[ind]){
                    dp[ind] = max(dp[ind], 1 + dp[prev_ind]);
                }
            }
            maxi = max(maxi, dp[ind]);
        }

        return maxi;
    }
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        //* Recursive Approach-> TLE
        // return rec(0, -1, n, nums);

        //* Dp Memoization->
        // (needs shifting of indexes)
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return f(0, -1, n, nums, dp);

        //* DP Tabulation-> TC-> O(n^2)
        // return tab(n, nums);

        //* Space Optimisation-> TC-> O(n^2)
        // return so(n, nums);

        //* Using Single DP Array Method-> TC-> O(n^2)
        return soo(n, nums);
    }
};