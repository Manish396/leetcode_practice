class Solution {
public:
    int findPeak(vector<int>nums, int s, int e, int n){
        int mid = (s+e)/2;
        if ((mid == 0 || nums[mid - 1] <= nums[mid]) && (mid == n - 1 || nums[mid + 1] <= nums[mid]))
            return mid;
        else if (mid > 0 && nums[mid - 1] > nums[mid])
            return findPeak(nums, s, (mid - 1), n);
        else
            return findPeak(nums, (mid + 1), e, n);
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n-1;
        int ans = findPeak(nums, s, e, n);
        return ans;
    }
};
