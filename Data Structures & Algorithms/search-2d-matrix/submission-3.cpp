class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix[0].size() - 1;
        int u = 0;
        int d = matrix.size() - 1;
        int hmid = (l + r)/2;
        if (target < matrix[0][0] || target > matrix[d][r]) {
            return false;
        }
        int t = -1;
        while (u <= d) {
            int vmid = (u + d)/2;
            if (target >= matrix[vmid][0]) {
                t = vmid;
                u = vmid + 1;
            } else {
                d = vmid - 1;
            }
        }
        cout << t << endl;
        while (l <= r) {
            hmid = (l+r)/2;
            if (target < matrix[t][hmid]) {
                r = hmid - 1;
            } else if (target > matrix[t][hmid]) {
                l = hmid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
