class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int r  = 0;
        string out = "";
        unordered_map<char, int> u;
        unordered_map<char, int> p;
        for (char c : t) {
            if (u.find(c) != u.end()) {
                u.find(c)->second++;
            } else {
                u.insert({c, 1});
            }
        }
        int need = u.size();
        int have = 0;
        for (r = 0; r < s.size(); r++) {
            if (p.find(s[r]) != p.end()) {
                p.find(s[r])->second++;
            } else {
                p.insert({s[r], 1});
            }
            if (u.find(s[r]) != u.end() && u.find(s[r])->second == p.find(s[r])->second) {
                have++;
            }
            while (l < s.size() && have == need) {
                if (out == "" || out.size() >= r-l+1) {
                    out = s.substr(l, r-l+1);
                }
                if (p.find(s[l]) != p.end()) {
                    p.find(s[l])->second--;    
                }
                if (u.find(s[l]) != u.end() && p.find(s[l])->second < u.find(s[l])->second) {
                    have--;
                }
                l++;
            }
        }
        return out;
    }
};
