class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<2) return n;
        
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        
        int maxNum = INT_MIN;
        
        for(int i = 2;i<=n;i++){
            dp[i] = i & 1 ? dp[i >> 1] + dp[(i >> 1) + 1] : dp[i >> 1];
            
            maxNum = max(maxNum,dp[i]);
        }
        return maxNum;
    }
};
