class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n),post(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre[i] = min(pre[i-1], nums[i]);
        }
        post[n-1] = nums[n-1];
        for(int i = n-2; i >=0; i--){
            post[i] = max(post[i+1], nums[i]);
        }
        for(int i = 0; i < n; i++){
            if(pre[i] < post[i] and nums[i]!=pre[i] and nums[i]!=post[i]){
                return true;
            }
        }
        return false;
    }
};
