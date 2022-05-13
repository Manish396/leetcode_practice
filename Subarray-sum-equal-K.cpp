class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long sum = 0, ans = 0;
        int n = nums.size();
        map<long long, long long>mp;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum == k){
                ans++;
            }
            if(mp.find(sum - k)!= mp.end()){
                ans += mp[sum - k];
            }
            mp[sum] += 1;
        }
        return ans;
    }
};
