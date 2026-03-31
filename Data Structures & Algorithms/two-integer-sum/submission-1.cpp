class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*bruteforce, for i, for j not equal to i, check if sum is equal matches*/
        vector<int> ans;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            for (auto it2 = nums.begin(); it2 != nums.end(); it2++) {
                if ((it!=it2) && (nums[it-nums.begin()] + nums[it2-nums.begin()] == target)) {
                    ans.push_back(it-nums.begin());
                    ans.push_back(it2-nums.begin());
                    return ans;
                }
            }
        }
        return ans;
    }
};
