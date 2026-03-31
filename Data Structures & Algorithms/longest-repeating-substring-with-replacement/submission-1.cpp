class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxcount = 0;
        int def = 0;
        int count = 0;
        unordered_set<char> us;
        for (char c : s) {
            us.insert(c);
        }
        for (left = 0; left < s.size(); left++) {
            for (char c : us) {
                count = 0;
                def = k;
                for (int r = left; (def >= 0) && (r < s.size()); r++) {
                    if (s[r] != c) {
                        if (def <= 0) {
                            break;
                        } else {
                            def--;
                            count++;
                        }
                    } else if (s[r] == c) {
                        count++;
                    }
                }
                maxcount = max(maxcount, count);
            }
        }
        return maxcount;
    }
};
