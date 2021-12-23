class Solution {
public:
    bool isPossible(vector<int>&nums, long val, int m){
        int curr = 0;
        for(auto it: nums){
            if(curr + it <= val){
                curr += it;
            }
            else{
                --m;
                curr = it;
                if(m < 0) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int ans = 0;
        int n = nums.size();
        long long high = 0, low = INT_MIN;
        for(int i = 0; i < n; i++){
            high += nums[i];
            low = max(low, (long long)nums[i]);
        }
        while(low <= high){
            int mid = (low + high)/2;
            if(isPossible(nums, mid, m-1)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
