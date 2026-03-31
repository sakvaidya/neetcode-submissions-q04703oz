class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>> m;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            if (m.find(t) != m.end()) {
                m[t].push_back(s);
            } else {
                m.insert({t, {s}});
            }
        }
        for (auto p : m) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
