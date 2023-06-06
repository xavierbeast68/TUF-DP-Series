//* https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//* https://www.youtube.com/watch?v=7win3dcgo3k

#include <bits/stdc++.h>

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.

	int totalSum = accumulate(begin(arr), end(arr), 0);
	// if totalSum is Odd, then array can't be partitioned into two subsets with equal sum 
	if(totalSum%2 == 1){
		return false;
	}
	// totalSum is even
	int k = totalSum/2; // target

	// Finding Subset Sum Equal to K
	//* DP (Tabulation + Space Optimisation)
	vector<bool> prev(k+1, 0);
    // Base Case
    //1) target == 0 (irrespective of value of ind)
    prev[0] = true;
    //2) if ind == 0, target == arr[0];
    if(arr[0] <= k) prev[arr[0]] = true;
    // Recurrence->
    // ind = 0, only at target = arr[0] remains true,others false
    for(int ind = 1; ind < n; ++ind){
        vector<bool> curr(k+1, 0);
        curr[0] = true; // for target == 0, always true
        // target = 0 already filled as true
        for(int target = 1; target <= k; ++target){
            bool notTake = prev[target];

            bool take = false;

            if(target >= arr[ind]){
                take = prev[target-arr[ind]];
            }

            curr[target] = (take | notTake);
        }
        prev = curr;
    }
    return prev[k];
}

