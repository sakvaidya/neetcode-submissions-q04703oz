class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stheap;
        for (int i: stones) {
            stheap.push(i);
        }
        int p1, p2;
        while (!stheap.empty()) {
            if (stheap.size() == 1) {
                return stheap.top();
            }
            p1 = stheap.top();
            stheap.pop();
            p2 = stheap.top();
            stheap.pop();
            if (p1 > p2) {
                stheap.push(p1-p2);
            }
        }
        return 0;
    }
};
