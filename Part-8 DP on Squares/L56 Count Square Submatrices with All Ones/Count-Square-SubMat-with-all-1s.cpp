//* https://www.codingninjas.com/codestudio/problems/count-square-submatrices-with-all-ones_3751502?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//* https://youtu.be/auS1fynpnjo

#include <bits/stdc++.h> 
using namespace std;

int countSquares(int n, int m, vector<vector<int>> &arr) {
    // Write your code here.

    vector<vector<int>> dp(n, vector<int> (m, 0));
    
    // Copy first row
    for(int i = 0; i < m; i++){
        dp[0][i] = arr[0][i];
    }
    // Copy first column
    for(int i = 0; i < n; i++){
        dp[i][0] = arr[i][0];
    }

    for(int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if (arr[i][j] == 0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum += dp[i][j];
        }
    }

    return sum;
}


