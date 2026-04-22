class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> t;
        if (nums.size() < k) {
            return -1;
        }
        for (int i : nums) {
            t.push(i);
        }
        for (int i = 0; i < k-1; i++) {
            t.pop();
        }
        return t.top();   
    }
};
