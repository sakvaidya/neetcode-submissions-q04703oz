class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> row[9];
        unordered_set<int> col[9];
        unordered_set<int> box[9];
        int rcount[9];
        int ccount[9];
        int boxcount[9];
        for (int i = 0; i < 9; i++) {
            rcount[i] = 0;
            ccount[i] = 0;
            boxcount[i] = 0;
        }
        int t = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    row[i].insert(board[i][j] - '0');
                    rcount[i]++;
                    if (row[i].size() < rcount[i]) {
                        return false;
                    }
                    col[j].insert(board[i][j] - '0');
                    ccount[j]++;
                    if (col[j].size() < ccount[j]) {
                        return false;
                    }
                    if (i <= 2) {
                        if (j <= 2) {
                            t = 0;
                        } else if (j <= 5) {
                            t = 1;
                        } else {
                            t = 2;
                        }
                    } else if (i <= 5) {
                        if (j <= 2) {
                            t = 3;
                        } else if (j <= 5) {
                            t = 4;
                        } else {
                            t = 5;
                        }
                    } else {
                        if (j <= 2) {
                            t = 6;
                        } else if (j <= 5) {
                            t = 7;
                        } else {
                            t = 8;
                        }
                    }
                    box[t].insert(board[i][j] - '0');
                    boxcount[t]++;
                    if (box[t].size() < boxcount[t]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
