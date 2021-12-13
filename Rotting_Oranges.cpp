class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0, rotten = 0;
        queue<pair<int, int>>qp;
        vector<vector<bool>>vis(m+1, vector<bool>(n+1, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    qp.push({i, j});
                }
            }
        }
        rotten = qp.size();
        bool fresh = false;
        while(!qp.empty()){
            pair<int, int>ij = qp.front();
            qp.pop();
            vis[ij.first][ij.second] = true;
            int dx[4] = {0, 0, 1, -1};
            int dy[4] = {1, -1, 0, 0};
            rotten--;
            for(int i = 0; i < 4; i++){
                int ni = ij.first + dx[i];
                int nj = ij.second + dy[i];
                if(ni >=0 and ni < m and nj >=0 and nj < n and grid[ni][nj] == 1 and !vis[ni][nj]){
                    qp.push({ni, nj});
                    fresh = true;
                    vis[ni][nj] = true;
                }
            }
            if(fresh and !rotten){
                ans++;
                rotten = qp.size();
                fresh = false;
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 and !vis[i][j]){
                    return -1;
                }
            }
        }
        return ans;
    }
};
