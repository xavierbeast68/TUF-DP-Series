//* https://www.codingninjas.com/codestudio/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//* https://youtu.be/tOylVCugy9k

#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int maxArea = INT_MIN;
    vector<int> nsr(n);
    vector<int> nsl(n);

    // Next Smaller Right
    stack<int> s;
    for(int i = n-1; i >= 0; --i){
        while(!s.empty() && heights[s.top()] >= heights[i]){
            s.pop();
        }
        if(s.empty()){
            nsr[i] = n;
        } else{
            nsr[i] = s.top();
        }
        s.push(i);
    }
    
    // Next Smaller left
    while(!s.empty()){
        s.pop();
    }
    for(int i = 0; i < n; ++i){
        while(!s.empty() && heights[s.top()] >= heights[i]){
            s.pop();
        }
        if(s.empty()){
            nsl[i] = -1;
        } else{
            nsl[i] = s.top();
        }
        s.push(i);
    }

    // Area->
    for(int i = 0; i < n; ++i){
        int ht = heights[i];
        int width = nsr[i] - nsl[i] - 1;
        int currArea = ht*width;
        maxArea = max(maxArea, currArea);
    }
    return maxArea;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	// Write your code here.

	vector<int> heights(m, 0);
	int maxArea = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j] == 1){
				heights[j] += 1;
			}
			else{
				heights[j] = 0;
			}
		}

		int area = largestRectangleArea(heights);
		maxArea = max(maxArea, area);
	}

	return maxArea;
}