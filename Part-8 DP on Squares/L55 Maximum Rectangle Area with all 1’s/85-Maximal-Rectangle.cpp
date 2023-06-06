//* https://leetcode.com/problems/maximal-rectangle/
//* https://youtu.be/tOylVCugy9k

class Solution{
public:
    int largestRectangleArea(vector<int> &heights){
        int n = heights.size();
        int maxArea = INT_MIN;

        vector<int> nsr(n);
        vector<int> nsl(n);

        // Next Smaller Right
        stack<int> s;
        for (int i = n - 1; i >= 0; --i){
            while (!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if (s.empty()){
                nsr[i] = n;
            }
            else{
                nsr[i] = s.top();
            }
            s.push(i);
        }

        // Next Smaller left
        while (!s.empty()){
            s.pop();
        }
        for (int i = 0; i < n; ++i)
        {
            while (!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }

            if (s.empty()){
                nsl[i] = -1;
            }
            else{
                nsl[i] = s.top();
            }
            s.push(i);
        }

        // Area->
        for (int i = 0; i < n; ++i){
            int ht = heights[i];
            int width = nsr[i] - nsl[i] - 1;
            int currArea = ht * width;
            maxArea = max(maxArea, currArea);
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (matrix[i][j] == '1'){
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
};