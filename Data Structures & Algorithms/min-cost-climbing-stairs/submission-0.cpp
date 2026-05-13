class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dist0;
        vector<int> dist1;
        for (int i = 0; i <= cost.size()+1; i++) {
            dist0.push_back(INT_MAX);
            dist1.push_back(INT_MAX);
        }
        dist0[0] = 0;
        dist1[0] = 0;
        dist1[1] = 0;
        for (int i = 0; i < cost.size(); i++) {
            dist0[i+1] = min(dist0[i]+cost[i], dist0[i+1]);
            dist0[i+2] = min(dist0[i]+cost[i], dist0[i+2]);
            if (i!= 0) {
                dist1[i+1] = min(dist1[i]+cost[i], dist1[i+1]);
                dist1[i+2] = min(dist1[i]+cost[i], dist1[i+2]);
            }
        }
        return min(dist0[cost.size()], dist1[cost.size()]);
    }
};
