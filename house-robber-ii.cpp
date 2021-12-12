class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        else if(n == 2){
            return max(nums[0], nums[1]);
        }
        int a1 = nums[0], a2 = max(nums[0], nums[1]);
        int ans1, ans2;
        for(int i = 2; i < n-1; i++){
            int temp = a2;
            a2 = max(a1 + nums[i], a2);
            a1 = temp;
        }
        ans1 = a2;
        a1 = nums[1], a2 = max(nums[1], nums[2]);
        for(int i = 3; i < n; i++){
            int temp = a2;
            a2 = max(a2, a1 + nums[i]);
            a1 = temp;
        }
        ans2 = a2;
        return max(ans1, ans2);
    }
};
