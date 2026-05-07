class Solution {
public:
    void setRC(vector<vector<int>>& m2, int m, int n) {
        for (int j = 0; j < m2[0].size(); j++) {
            m2[m][j] = 0;
        }
        for (int i = 0; i < m2.size(); i++) {
            m2[i][n] = 0;
        }
        return;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> m2 = matrix;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    setRC(m2, i, j);    
                }
            }
        }
        matrix = m2;
    }
};
