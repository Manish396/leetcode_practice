class Solution {
public:
    vector<vector<int>>dp;
    bool solve(string &s,string &p,int i,int j){
        if(i >= s.size() && j >= p.size()) 
            return true;
        if(dp[i][j] != -1) 
            return dp[i][j];
        bool match =  (i < s.size()) && (s[i] == p[j] || p[j] == '.');
        if(j+1 < p.size() && p[j+1] == '*'){
            return dp[i][j] = (match && (solve(s, p, i+1,j))) || solve(s, p, i, j+2);           
        }
        else if(j < p.size() && match){
            return dp[i][j] = solve(s,p,i+1,j+1);               
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        dp.resize(s.size()+1,vector<int>(p.size()+1,-1));
        return solve(s,p,0,0);
    }
};
