class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dist;
        for (int i = 0; i <= cost.size()+1; i++) {
            dist.push_back(INT_MAX);
        }
        dist[0] = 0;
        dist[1] = 0;
        for (int i = 0; i < cost.size(); i++) {
            dist[i+1] = min(dist[i]+cost[i], dist[i+1]);
            dist[i+2] = min(dist[i]+cost[i], dist[i+2]);
        }
        return dist[cost.size()];
    }
};
