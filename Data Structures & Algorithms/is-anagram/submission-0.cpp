class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char> s1(s.begin(), s.end());
        vector<char> s2(t.begin(), t.end());
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        auto i = s1.begin();
        auto j = s2.begin();
        while ((i != s1.end()) && (j != s2.end())) {
            if (s1[i-s1.begin()] != s2[j-s2.begin()]) {
                return false;
            }
            i++;
            j++;
        }
        if (i != s1.end() || j != s2.end()) {
            return false;
        }
        return true;
    }
};
