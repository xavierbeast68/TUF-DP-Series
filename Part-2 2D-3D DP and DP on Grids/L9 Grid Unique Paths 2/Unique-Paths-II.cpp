//* https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//* https://youtu.be/TmhpgXScLyY

int mod = 1e9 + 7;

int rec(int row, int col, vector<vector<int>>& mat, vector<vector<int>>& dp){
    if(row >= 0 && col >= 0 && mat[row][col] == -1){
        return 0;
    }
	if(row == 0 && col == 0){
		return 1;
	}
	if(row < 0 || col < 0){
		return 0;
	}

	if(dp[row][col] != -1){
		return dp[row][col];
	}

	int up = rec(row-1,col, mat, dp);
	int left = rec(row,col-1, mat, dp);
	return dp[row][col] = (up + left) % mod;
}

int mazeObstacles(int m, int n, vector< vector< int> > &mat) {
    // Write your code here

    //* Recrusive Soln-> TLE
	// return rec(m-1,n-1, mat);

	//* DP Memoization->
	// vector<vector<int>> dp(m, vector<int>(n,-1));
	// return rec(m-1,n-1, mat, dp);

	//* DP Tabulation->
	// int dp[m][n];
	// for(int i = 0; i < m; ++i){
	// 	for(int j = 0; j < n; ++j){
    //      if(mat[i][j] == -1){
    //          dp[i][j] = 0;
    //      }
	// 		else if(i == 0 && j == 0){
	// 			dp[i][j] = 1;
	// 		}
	// 		else{
	// 			int up = 0, left = 0;
	// 			if(i > 0){
	// 				up = dp[i-1][j];
	// 			}
	// 			if(j > 0){
	// 				left = dp[i][j-1];
	// 			}

	// 			dp[i][j] = (up + left) % mod;
	// 		}
	// 	}
	// }
	// return dp[m-1][n-1];

	//* DP (Tabulation + Space Optimisation)
	vector<int> prev(n, 0);
	for(int i = 0; i < m; ++i){
		vector<int> temp(n, 0);
		for(int j = 0; j < n; ++j){
            if(mat[i][j] == -1){
                temp[j] = 0;
            }
			else if(i == 0 && j == 0){
				temp[j] = 1;
			}
			else{
                
				int up = 0, left = 0;
				if(i > 0){
					up = prev[j];
				}
				if(j > 0){
					left = temp[j-1];
				}

				temp[j] = (up + left) % mod;
			}
		}
		prev = temp;
	}
	return prev[n-1];
}