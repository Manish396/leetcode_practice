class Solution {
public:
    void dfs(vector<int>adj[], vector<bool>&vis, int i, string &s, string &temp, vector<int>&idx){
        temp += s[i];
        vis[i] = true;
        idx.push_back(i);
        for(auto it: adj[i]){
            if(!vis[it])
                dfs(adj, vis, it, s, temp, idx);
        }
        return;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<int>adj[n];
        for(auto it: pairs){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n + 1, false);
        for(int i = 0; i < n; i++){
            string temp = "";
            vector<int>idx;
            if(!vis[i]){
                dfs(adj, vis, i, s, temp, idx);
                sort(idx.begin(), idx.end());
                sort(temp.begin(), temp.end());
                int j = 0;
                for(auto it: idx){
                    s[it] = temp[j++];
                }
            }
        }
        return s;
    }
};
