class Solution {
public:
    void dfs(int source , int destination , vector<vector<int>>& adj , vector<int>& path , vector<vector<int>>& paths){
        if(source == destination){
            path.push_back(source) ; 
            paths.push_back(path) ; 
            path.pop_back() ; 
        }
        path.push_back(source) ; 
        for(auto i : adj[source]){
            dfs(i , destination , adj , path , paths) ; 
        }
        path.pop_back() ;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        vector<vector<int>> paths ; 
        vector<int> path ; 
        int n = adj.size() ; 
        dfs(0 , n - 1 , adj , path , paths) ; 
        return paths ; 
    }
};
