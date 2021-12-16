class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size(); 
        
        unordered_map<char, vector<int>>mcv; 
        for (int i = 0; i < n; ++i) 
            mcv[t[i]].push_back(i); 
        
        vector<long long int> ans(n+1); 
        ans[n] = 1; 
        
        for (int i = m-1; i >= 0; --i) 
            for (auto& k : mcv[s[i]]) 
                ans[k] = (ans[k] + ans[k+1])%1000000007; 
        return ans[0]; 
    }
};
