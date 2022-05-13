class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        vector<long long>dp(10001, INT_MAX);
        for(auto it : coins){
            if(it <= amount)
                dp[it] = 1;
        }
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            long long x = INT_MAX;
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0){
                    x = min(x, dp[i - coins[j]]);
                }
            }
            if(x == INT_MAX){
                dp[i] = x;
            }
            else{
                dp[i] = x + 1;
            }
        }
        if(dp[amount] == INT_MAX) dp[amount] = -1;
        return dp[amount];
    }
};
