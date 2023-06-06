//* https://leetcode.com/problems/house-robber/
//* https://www.youtube.com/watch?v=3WaxQMELSkw

class Solution {
public:
    int maxAmt(vector<int>& nums){
        int prev1 = nums[0], prev2 = 0;
        for(int i = 1; i < nums.size(); ++i){
            int take = nums[i];
            if(i > 1){
                take += prev2;
            }
            int notTake = 0 + prev1;
            prev2 = prev1;
            prev1 = max(take, notTake);
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        return maxAmt(nums);
    }
};