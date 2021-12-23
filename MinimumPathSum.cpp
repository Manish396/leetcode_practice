class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        vector<vector<int>>vis(grid.size(), vector<int>(grid[0].size(), -1));
        queue<pair<int, int>>qp;
        qp.push({0, 0});
        vis[0][0] = grid[0][0];
        while(!qp.empty()){
            pair<int, int>id = qp.front();
            qp.pop();
            if(id.first +1 < n){
                if(vis[id.first + 1][id.second] == -1){
                    vis[id.first + 1][id.second] = vis[id.first][id.second] + grid[id.first+1][id.second];
                    qp.push({id.first+1, id.second});
                }
                else{
                    vis[id.first + 1][id.second] = min(vis[id.first + 1][id.second], vis[id.first][id.second] + grid[id.first+1][id.second]);
                }
            }
            if(id.second +1 < grid[0].size()){
                if(vis[id.first][id.second+1] == -1){
                    vis[id.first][id.second + 1] = vis[id.first][id.second] + grid[id.first][id.second+1];
                    qp.push({id.first, id.second+1});
                }
                else{
                    vis[id.first][id.second+1] = min(vis[id.first][id.second + 1], vis[id.first][id.second] + grid[id.first][id.second + 1]);
                }
            }
        }
        return vis[n-1][vis[0].size() - 1];
    }
};
