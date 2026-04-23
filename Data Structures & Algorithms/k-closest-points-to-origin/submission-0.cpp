class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (points.size() < k) {
            return {};
        }
        multimap<float, vector<int>> m;
        for (vector<int> p : points) {
            float dist = sqrt(pow(p[0], 2) + pow(p[1], 2));
            m.insert({dist, p});
        }
        vector<vector<int>> out;
        for (int i = 0; i < k; i++) {
            out.push_back(m.begin()->second);
            m.erase(m.begin());
        }
        return out;
    }
};
