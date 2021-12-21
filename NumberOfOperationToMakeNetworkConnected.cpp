class Solution {
public:
    void dfs(int x, vector<bool>&vis, vector<int>adj[]){
        vis[x] = true;
        for(auto it: adj[x]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m < n-1){
            return -1;
        }
        vector<int>adj[n+1];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n, false);
        int ans = 0;
        for(int i = 0; i <= n-1; i++){
            if(!vis[i]){
                dfs(i, vis, adj);
                ans++;
            }
        }
        return ans-1;
    }
};
