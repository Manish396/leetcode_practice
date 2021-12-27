class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int dfs(vector<vector<int>>&matrix, vector<vector<int>>&dist, int i, int j){
        if(dist[i][j] > 0) 
            return dist[i][j];
        int ans = 0;
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni >=0 and ni < matrix.size() and nj >=0 and nj < matrix[0].size() and matrix[ni][nj] > matrix[i][j]){
                ans = max(ans, dfs(matrix, dist, ni, nj));
            }
        }
        dist[i][j] = ans + 1;
        return ans + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>>dist(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, dfs(matrix, dist, i, j));
            }
        }
        // dist.clear();
        return ans;
    }
};
