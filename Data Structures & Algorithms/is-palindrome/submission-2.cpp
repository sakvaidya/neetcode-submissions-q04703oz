class Solution {
public:
    bool isPalindrome(string s) {
        string j = "";
        for (char c : s) {
            if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9'))) {
                j.push_back(tolower(c));
            }
        }
        int left = 0;
        int right = j.size() - 1;
        while (right > left) {
            if (j[left] != j[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
