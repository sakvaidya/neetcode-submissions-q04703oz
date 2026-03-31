class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count = 1;
        int curcount = 1;
        int j = 0;
        set<int> s;
        for (int v : nums) {
            s.insert(v);
        }
        if (s.size() == 0) {
            return 0;
        }
        for (int i : s) {
            if (j == 0 && (s.find(i+1)) != s.end()) {
                j = 1;
                curcount++;
            } else if (j == 1 && (s.find(i+1) != s.end())) {
                curcount++;
            } else if (j == 1 && (s.find(i+1) == s.end())) {
                j = 0;
                if (curcount > count) {
                    count = curcount;
                }
                curcount = 1;
            }
        }
        return count;
    }
};
