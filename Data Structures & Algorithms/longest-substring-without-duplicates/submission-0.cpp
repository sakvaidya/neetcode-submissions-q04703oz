class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> unique;
        int left = 0;
        int maxlength = 0;
        int curlength = 0;
        for (int right = 0; right < s.size(); right++) {
            while(unique.find(s[right]) != unique.end()) {
                unique.erase(s[left]);
                left++;
                curlength--;
            }
            unique.insert(s[right]);
            curlength++;
            if (maxlength < curlength) {
                maxlength = curlength;
            }
        }
        return maxlength;
    }
};
