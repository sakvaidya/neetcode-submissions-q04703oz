class Solution {
public:
    int search(vector<int>& nums, int target) {
       int l = 0;
       int r = nums.size() - 1;
       if (nums[l] > target || nums[r] < target) {
            return -1;
       }
       while (l <= r) {
            int mid = (l+r+1)/2;
            if (nums[l] == target) {
                return l;
            } else if (nums[r] == target) {
                return r;
            }
            if (target > nums[mid]) {
                l = mid + 1;
            } else if (target < nums[mid]) {
                r = mid - 1;
            } else {
                return mid;
            }
       }
       return -1; 
    }
};
