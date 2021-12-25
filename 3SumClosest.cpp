class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int ans = INT_MAX;
        for(int i=0;i < nums.size()-1; i++){
            int sum = target - nums[i];
            int s = i+1;
            int e = nums.size()-1;
            while(s < e){
                if(nums[s] + nums[e] == sum)
                    return target;
                
                if(abs(nums[s] + nums[e]-sum) < abs(ans))
                    ans = nums[s] + nums[e] - sum;
                
                if(nums[s]+nums[e] < sum){
                    s++;
                }
                else{
                    e--;
                }
            }
        }
        return ans + target;
    }
};
