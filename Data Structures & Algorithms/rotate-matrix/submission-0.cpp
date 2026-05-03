class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        cout << matrix.size();
        for (int i = 0; i < (matrix.size()+1)/2; i++) {
            vector<int> temp = matrix[i];
            matrix[i] = matrix[matrix.size()-1-i];
            matrix[matrix.size()-1-i] = temp;
        } 
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};
