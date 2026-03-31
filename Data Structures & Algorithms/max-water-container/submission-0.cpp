class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea= 0;
        int l = 0;
        int r = heights.size() - 1;
        int val;
        while (l < r) {
            val = (r-l) * min(heights[l], heights[r]);
            if (val > maxarea) {
                maxarea = val;
            }

            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxarea;
    }
};
