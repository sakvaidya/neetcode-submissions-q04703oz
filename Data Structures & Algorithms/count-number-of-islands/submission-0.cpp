class Solution {
public:
    void fillisland(vector<vector<char>>& grid, int i , int j, int count) {
        if (grid[i][j] == '1') {
            grid[i][j] = '0';
            if (i != 0) {
                fillisland(grid, i-1, j, count);
            }
            if (i != grid.size()-1) {
                fillisland(grid, i+1, j, count);
            }
            if (j != 0) {
                fillisland(grid, i, j-1, count);
            }
            if (j != grid[i].size()-1) {
                fillisland(grid, i, j+1, count);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    fillisland(grid, i, j, count);
                }
            }
        }
        return count;
    }
};
