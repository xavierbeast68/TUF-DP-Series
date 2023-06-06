//* https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    //  Write your code here.

    int mod = 1e9 + 7;
    int a = 0, b = 1;
    for(int i = 0; i < nStairs; ++i){
        int temp = (a + b)%mod;
        a = b;
        b = temp;
    }

    return b;
}