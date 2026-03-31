class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        vector<int> dups;
        auto it1 = nums.begin();
        auto it2 = dups.begin();
        while (it1 != nums.end()) {
            for (it2 = dups.begin(); it2 != dups.end(); it2++) {
                if (nums[it1-nums.begin()] == dups[it2-dups.begin()]) {
                    return true;
                }
            }
            dups.push_back(nums[it1-nums.begin()]);
            it1++;
        }
        return false;
    }
};