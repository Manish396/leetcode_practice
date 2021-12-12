class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int dp = 0;
        for(int i = 0; i < n; i++){
            dp = max(dp, i + nums[i]);
            if(dp <= i and i!=n-1){
                return false;
            }
        }
        return true;
    }
};
