class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> max(prices.size());
        vector<int> min(prices.size());
        if (prices.size() < 2) {
            return 0;
        }
        int minm = prices[0];
        int maxm = prices[prices.size() - 1];
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minm) {
                minm = prices[i];
            }
            min[i] = minm;
        }
        for (int i = prices.size() - 1; i >= 0; i--) {
            if (prices[i] > maxm) {
                maxm = prices[i];
            }
            max[i] = maxm;
        }
        int diffm = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (max[i]-min[i] > diffm) {
                diffm = max[i]-min[i];
            }
        }
        return diffm;
    }
};
