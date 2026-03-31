class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        //val, index
        unordered_map<int, int> st;
        int j = 0;
        int k = 0;
        for (int i : numbers) {
            ++j;
            st.insert({i, j});
        }
        for (auto it = st.begin(); it != st.end(); it++) {
            if (st.find(target - it->first) != st.end()) {
                k = st.find(target - it->first)->second;
                if (it->second < k) {
                    ans.push_back(it->second);
                    ans.push_back(st.find(target - it->first)->second);
                } else {
                    ans.push_back(st.find(target - it->first)->second);
                    ans.push_back(it->second);
                }
                return ans;
            }
        }
        return ans;
    }
};
