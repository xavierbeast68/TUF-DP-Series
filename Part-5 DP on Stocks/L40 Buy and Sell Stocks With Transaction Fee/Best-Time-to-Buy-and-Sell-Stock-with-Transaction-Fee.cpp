//* https://www.codingninjas.com/codestudio/problems/rahul-and-his-chocolates_3118974?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//* https://youtu.be/k4eK-vEmnKg

#include <bits/stdc++.h>
using namespace std;

int soo(vector<int>& prices, int n, int fee){
    int aheadBuy = 0, aheadNotBuy = 0, currBuy = 0, currNotBuy = 0;

    for(int ind = n-1; ind >= 0; --ind){
        // buy = 0
        currNotBuy = max(prices[ind] + aheadBuy, 0 + aheadNotBuy);

        // buy = 1;
        currBuy = max(-prices[ind] - fee + aheadNotBuy, 0 + aheadBuy);

        aheadBuy = currBuy;
        aheadNotBuy = currNotBuy;
    }

    return aheadBuy;
}

int maximumProfit(int n, int fee, vector<int> &prices) {
    // Write your code here.

    //* DP Space Optimisation using variables->
    // https://www.codingninjas.com/codestudio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
    return soo(prices, n, fee);
}
