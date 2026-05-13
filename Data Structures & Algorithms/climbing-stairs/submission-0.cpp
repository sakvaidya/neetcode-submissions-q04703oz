class Solution {
public:
    int climbStairs(int n) {
        vector<int> t;
        for (int i = 0; i <= n+1; i++) {
            t.push_back(0);
        }
        t[1] = 1;
        t[2] = 1;
        for (int i = 0; i < n; i++) {
            t[i+1] += t[i];
            t[i+2] += t[i];
        }
        return t[n];
    }
};
