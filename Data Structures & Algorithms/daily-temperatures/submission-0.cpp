class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        for (int i = 0; i < temperatures.size(); i++) {
            int count = 0;
            for (count = i; temperatures[i]>=temperatures[count] && count < temperatures.size(); count++) {
            }
            if (count == temperatures.size()) {
                count = 0;
            } else {
                count = count - i;
            }
            res.push_back(count);
        }
        return res;
    }
};
