class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        vector<int> p = piles;
        int l = 1;
        sort(p.begin(), p.end());
        int r = p[p.size()-1];
        int mid;
        int up;
        if (p.size() > h) {
            return -1;
        }
        int t;
        while (l <= r) {
            up = 0;
            mid = (l+r)/2;
            for (int i = 0; i < p.size(); i++) {
                up += ceil((double)p[i] / (double)mid);
            }
            if (up <= h) {
                t = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return t;
    }
};
