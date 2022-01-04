class Solution {
public:
    bool dfs(int node,vector<int> adj[],vector<bool> &vis,vector<bool> &dfsvis,vector<int> &res) {
        vis[node]=true;
        dfsvis[node]=true;
        for(int i=0;i<adj[node].size();i++) {
            if(!vis[adj[node][i]]) {
                if(dfs(adj[node][i],adj,vis,dfsvis,res)) {
                    return true;
                }
            }
            else if(dfsvis[adj[node][i]]) {
                return true;
            }
        }
        dfsvis[node]=false;
        res.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> dfsvis(numCourses,false);
        vector<int> res;
        for(int i=0;i<numCourses;i++) {
            if(!vis[i]) {
                if(dfs(i,adj,vis,dfsvis,res)) {
                    return {};
                }
            }
        }
        return res;
    }
};
