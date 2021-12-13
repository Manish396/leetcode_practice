class Solution {
public:
    void dfs(vector<vector<char>>&grid, int i, int j, int m, int n){
        if(!(i >= 0 and i < m and j >= 0 and j < n and grid[i][j] == '1')){
            return;
        }
        grid[i][j] = '0';
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            dfs(grid, ni, nj, m, n);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int island = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j, m, n);
                    island++;
                }
            }
        }
        return island;
    }
};
