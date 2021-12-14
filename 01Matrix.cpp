class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        queue<pair<int, int>>qp;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    qp.push({i, j});
                    vis[i][j] = 1;
                }
                else{
                    mat[i][j] = INT_MAX;
                }
            }
        }
        while(!qp.empty()){
            pair<int,int>p = qp.front();
            qp.pop();
            int dx[4] = {0, 0, 1, -1};
            int dy[4] = {1, -1, 0, 0};
            for(int k = 0; k < 4; k++){
                int ni = p.first + dx[k];
                int nj = p.second + dy[k];
                if(ni >=0 and ni < m and nj >=0 and nj < n and !vis[ni][nj]){
                    mat[ni][nj] = min(mat[ni][nj], mat[p.first][p.second]+1);
                    qp.push({ni, nj});
                    vis[ni][nj] = 1;
                }
            }
        }
        return mat;
    }
};
