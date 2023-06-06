//* https://www.codingninjas.com/codestudio/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
long long maxAmt(vector<long long>& nums){
    long long prev1 = nums[0], prev2 = 0;
    for(int i = 1; i < nums.size(); ++i){
        long long take = nums[i];
        if(i > 1){
            take += prev2;
        }

        long long notTake = 0 + prev1;

        prev2 = prev1;
        prev1 = max(take, notTake);
    }
    return prev1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    if(valueInHouse.size() == 1){
        return valueInHouse[0];
    }
    
    vector<long long> temp1, temp2;
    for(int i = 0; i < valueInHouse.size(); ++i){
        if(i != 0)temp1.push_back(valueInHouse[i]);
        if(i != valueInHouse.size()-1)temp2.push_back(valueInHouse[i]);
    }
    return max(maxAmt(temp1), maxAmt(temp2));
}