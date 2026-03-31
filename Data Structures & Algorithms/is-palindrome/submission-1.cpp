class Solution {
public:
    bool isPalindrome(string s) {
        string j = "";
        for (char c : s) {
            if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9'))) {
                j.push_back(tolower(c));
            }
        }
        string t = j;
        reverse(t.begin(), t.end());
        if (j == t) {
            return true;
        }
        return false;
    }
};
