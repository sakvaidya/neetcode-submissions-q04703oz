class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> val;
        vector<int> out;
        int l = 0;
        int r;
        for (int i = 0; i < k; i++) {
            if (val.find(nums[i]) != val.end()) {
                val.find(nums[i])->second++;
            } else {
                val.insert({nums[i], 1});
            }
        }
        out.push_back(val.rbegin()->first);
        for (r = k; r < nums.size(); r++) {
            if (val.find(nums[r]) != val.end()) {
                val.find(nums[r])->second++;
            } else {
                val.insert({nums[r], 1});
            }
            if (val.find(nums[l])->second <= 1) {
                val.erase(nums[l]);
            } else {
                val.find(nums[l])->second--;
            }
            out.push_back(val.rbegin()->first);
            l++;
        }
        return out;
    }
};
