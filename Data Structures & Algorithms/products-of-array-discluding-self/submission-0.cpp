class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out;
        int i = 0;
        int tz = -1;
        int prod = 1;
        for (int k = 0; k < nums.size(); k++) {
            if (nums[k] == 0 && (tz != -1)) {
                for (int m = 0; m < nums.size(); m++) {
                    out.push_back(0);
                }
                return out;
            } else if (nums[k] == 0 && (tz == -1)) {
                tz = k;
            } else {
                prod *= nums[k];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (tz == -1) {
                out.push_back(prod/nums[i]); 
            } else {
                if (i == tz) {
                    out.push_back(prod);
                } else {
                    out.push_back(0);
                }
            }
        }
        return out;
    }
};
