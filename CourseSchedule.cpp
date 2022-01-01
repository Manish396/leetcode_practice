class Solution {
public:
    bool dfs(vector<int>adj[], vector<int>&visited, vector<int>&currVis, int i){
        if(visited[i] == false){
            visited[i] = true;
            currVis[i] = true;
            for(auto it: adj[i]){
                if(!visited[it] and dfs(adj, visited, currVis, it)){
                    return true;
                }
                else if(currVis[it]){
                    return true;
                }
            }
        }
        currVis[i] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses + 1];
        for(int i = 0; i < prerequisites.size(); i++){
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            adj[y].push_back(x);
        }
        vector<int>visited(numCourses + 1, 0);
        vector<int>currVis(numCourses + 1, 0);
        for(int i = 0; i < numCourses; i++){
            if(dfs(adj, visited, currVis, i)){
                return false;
            }
        }
        return true;
    }
};
