class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
        find perm of s1 in s2
        */
        unordered_map<char, int> u;
        unordered_map<char, int> p;
        for (char c : s1) {
            if (u.find(c) != u.end()) {
                u.find(c)->second = u.find(c)->second + 1; 
            } else {
                u.insert({c, 1});
            }
        }
        p = u;
        for (int i = 0; i < s2.size(); i++) {
            for (int j = i; (j < s2.size()) && (p.find(s2[j]) != p.end()) && (p.find(s2[j])->second > 0); j++) {
                char c = s2[j];
                if (p.find(c)->second <= 1) {
                    p.erase(c);
                } else {
                    p.find(c)->second = p.find(c)->second - 1;
                }
                if (p.empty()) {
                    return true;
                }
            }
            p = u;
        }
        return false;
    }
};
