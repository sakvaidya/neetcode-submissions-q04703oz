class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int ans = 0;
        for (int i = 0; i < tokens.size(); i++) {
            string val = tokens[i];
            int t = 0;
            int p1, p2;
            if (val == "+") {
                if (!s.empty()) {
                    p2 = s.top();
                    s.pop();
                    p1 = s.top();
                    s.pop();
                    s.push(p1 + p2);
                }
            } else if (val == "-") {
                if (!s.empty()) {
                    p2 = s.top();
                    s.pop();
                    p1 = s.top();
                    s.pop();
                    s.push(p1 - p2);
                }
            } else if (val == "*") {
                if (!s.empty()) {
                    p2 = s.top();
                    s.pop();
                    p1 = s.top();
                    s.pop();
                    s.push(p1 * p2);
                }
            } else if (val == "/") {
                if (!s.empty()) {
                    p2 = s.top();
                    s.pop();
                    p1 = s.top();
                    s.pop();
                    s.push(p1 / p2);
                }
            } else {
                int sgn = 1;
                if (val[0] == '-') {
                    sgn = -1;
                }
                for (char c : val) {
                    if (c >= '0' && c <= '9') {
                        t = t * 10 + (c - '0');
                    }
                }
                t *= sgn;
                s.push(t);
            }
        }
        ans = s.top();
        s.pop();
        return ans;
    }
};
