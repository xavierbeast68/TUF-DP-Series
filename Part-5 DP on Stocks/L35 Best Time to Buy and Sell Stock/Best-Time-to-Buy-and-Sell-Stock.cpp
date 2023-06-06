//* https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//* https://youtu.be/excAOvwF_Wk

#include <bits/stdc++.h> 
using namespace std;

int maximumProfit(vector<int> &prices){
    // Write your code here.

    int maxProfit = 0;
        int mini = prices[0];

    for(int i = 1; i < prices.size(); ++i){
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }

    return maxProfit;
}