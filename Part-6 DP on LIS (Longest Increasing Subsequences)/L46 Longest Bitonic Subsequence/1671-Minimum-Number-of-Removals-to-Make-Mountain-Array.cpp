//* https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
//* https://youtu.be/y4vN0WNdrlg

class Solution{
public:
    void dbg(vector<int>& arr){
        for(auto i : arr){
            cout<< i << " ";
        }
        cout << endl;
    }
    int f(vector<int> &nums, int n){
        vector<int> dp1(n, 1);

        // LIS from Front->
        for (int i = 0; i < n; i++){
            for (int prev = 0; prev < i; prev++){
                if (nums[prev] < nums[i] && (1 + dp1[prev] > dp1[i])){
                    dp1[i] = 1 + dp1[prev];
                }
            }
        }dbg(dp1);

        vector<int> dp2(n, 1);
        // LIS from back
        for (int i = n - 1; i >= 0; i--){
            for (int prev = n - 1; prev > i; prev--){
                if (nums[prev] < nums[i] && (1 + dp2[prev] > dp2[i])){
                    dp2[i] = 1 + dp2[prev];
                }
            }
        }dbg(dp2);

        int maxi = 1;
        // not including end points, to avoid cases of strictly increasing and strictly decreasing
        for(int i = 1; i < n-1; i++){
            // Edge case
            if(dp1[i] > 1 && dp2[i] > 1){
                maxi = max(maxi, dp1[i]+dp2[i]-1);
            }
        }

        cout << maxi;
        return maxi;
    }
    int minimumMountainRemovals(vector<int> &nums){
        int n = nums.size();
        //* DP (LIS)
        return (n - f(nums, n));
    }
};