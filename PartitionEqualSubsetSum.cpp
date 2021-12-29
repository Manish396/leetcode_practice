class Solution {
public:
    bool targetMet(vector<int>&nums,  int tar){
        int n = nums.size();
        bool dp[n+1][tar+1];
        for(int i = 0; i <= tar; i++){
            dp[0][i] = false;
        }
        for(int i = 0; i <= n; i++){
            dp[i][0] = true;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= tar; j++){
                dp[i][j] = dp[i-1][j];
                if(j >= nums[i-1]){
                    dp[i][j] = dp[i][j] || dp[i-1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][tar];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        int tar = sum/2;
        if(targetMet(nums, tar)){
            return true;
        }
        else{
            return false;
        }
    }
};
