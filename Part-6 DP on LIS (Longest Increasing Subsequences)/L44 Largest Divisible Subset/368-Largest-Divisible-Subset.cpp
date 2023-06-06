//* https://leetcode.com/problems/largest-divisible-subset/
//* https://youtu.be/gDuZwBW9VvM

class Solution {
public:
    vector<int> f(vector<int>& nums, int n){
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastIndex = 0;

        sort(begin(nums), end(nums));

        for(int i = 0; i < n; ++i){
            hash[i] = i;
            for(int prev = 0; prev < i; ++prev){
                if(nums[i]%nums[prev] == 0 && dp[i] < (1 + dp[prev])){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }

        return ans;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //* DP (Longest Increasing Subsequence)->
        int n = nums.size();
        return f(nums, n);
    }
};