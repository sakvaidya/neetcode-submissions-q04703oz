struct order {
    bool operator()(const auto& a, const auto& b) const {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //count, num
        vector<int> ans;
        map<int, int> m;
        for (int n : nums) {
            if (m.find(n) != m.end()) {
                m[n] += 1;
            } else {
                m.insert({n, 1});
            }
        }
        vector<pair<int, int>> dump(m.begin(), m.end());
        sort(dump.begin(), dump.end(), order());
        for (int i = 0; i < k; i++) {
            ans.push_back(dump[i].first);
        }
        return ans;
    }
};
