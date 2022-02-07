class Solution {
public:
    void dfs(vector<vector<int>>&vec, int i, vector<bool>&vis){
        for(int j = 0; j < vec.size(); j++){
            if(vec[i-1][j] == 1 and !vis[j + 1]){
                vis[j + 1] = true;
                dfs(vec, j + 1, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>vis(n + 1, false);
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(isConnected, i, vis);
                cnt++;
            }
        }
        return cnt;
    }
};
