class Solution {
public:

    string encode(vector<string>& strs) {
        string out = "";
        for (const string& strr : strs) {
            out+= to_string(strr.length());
            out.push_back('#');
            out += strr;
        }
        return out;
    }

    vector<string> decode(string s) {
        vector<string> out;
        string temp = "";
        int i = 0;
        int l = 0;
        for (char c : s) {
            if (i == 0 && c != '#') {
                l *= 10;
                l += c - '0';
            } else if (i == 0 && c == '#') {
                if (l == 0) {
                    out.push_back("");
                } else {
                    i = 1;
                    temp = "";
                }
            } else if (i == 1 && l > 0) {
                l--;
                temp.push_back(c);
                if (l == 0) {
                    out.push_back(temp);
                    i = 0;
                }
            }
        }
        return out;
    }
};
