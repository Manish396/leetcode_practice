class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int>freq(10005), dp(20005);
        int maxi = INT_MIN;
        for(auto it: nums){
            freq[it]++;
            maxi = max(maxi, it);
        }
        dp[1] = 1*freq[1];
        for(int i = 2; i <= maxi; i++){
            dp[i] = max(i*freq[i]+ dp[i - 2], dp[i - 1]);
        }
        return dp[maxi];
    }
};
