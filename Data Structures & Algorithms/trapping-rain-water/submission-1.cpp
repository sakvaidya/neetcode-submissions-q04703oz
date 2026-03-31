class Solution {
public:
    int trap(vector<int>& height) {
        int tottrap = 0;
        int h1 = 0;
        if (!height.size()) {
            return 0;
        }
        int h2 = height.size() - 1;
        int maxL = height[h1];
        int maxR = height[h2];
        int val = 0;
        while (h1 < h2) {
            if (maxL <= maxR) {
                val = maxL - height[h1];
                if (val > 0) {
                    tottrap += val;
                }
                h1++;
                if (height[h1] > maxL) {
                    maxL = height[h1];
                }
            } else {
                val = maxR - height[h2];
                if (val > 0) {
                    tottrap += val;
                }
                h2--;
                if (height[h2] > maxR) {
                    maxR = height[h2];
                }
            }
        }
        return tottrap;
    }
};
