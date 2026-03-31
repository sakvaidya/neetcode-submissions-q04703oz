class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int curminbar;
        int curarea;
        int maxarea = INT_MIN;
        for (int i = 0; i < heights.size(); i++) {
            curminbar = heights[i];
            for (int j = i; j < heights.size(); j++) {
                if (heights[j] < curminbar) {
                    curminbar = heights[j];
                }
                curarea = (j-i+1)*(curminbar);
                if (curarea > maxarea) {
                    maxarea = curarea;
                }
            }
        }
        return maxarea;
    }
};
