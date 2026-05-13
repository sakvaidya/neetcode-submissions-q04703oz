class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> earn;
        for (int i = 0; i < nums.size(); i++) {
            earn.push_back(nums[i]);
        }
        int mm = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (earn[i] > mm) {
                mm = earn[i];
            }
            earn[i+2] = mm+earn[i+2];
        }
        int m = earn[0];
        for (int i = 0; i < earn.size(); i++) {
            if (earn[i] > m) {
                m = earn[i];
            }
        }
        return m;
    }
};
