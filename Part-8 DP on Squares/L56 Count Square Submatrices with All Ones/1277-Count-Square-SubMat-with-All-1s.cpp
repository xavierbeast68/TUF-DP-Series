//* https://leetcode.com/problems/count-square-submatrices-with-all-ones/
//* https://youtu.be/auS1fynpnjo

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int> (m, 0));
    
        // Copy first row
        for(int i = 0; i < m; i++){
            dp[0][i] = matrix[0][i];
        }
        // Copy first column
        for(int i = 0; i < n; i++){
            dp[i][0] = matrix[i][0];
        }

        for(int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                if (matrix[i][j] == 0){
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
};