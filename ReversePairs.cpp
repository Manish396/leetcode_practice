class Solution {
public:
    int count;
    void merge(vector<int>& nums, int s, int mid, int e)
    {
        int i = s, j = mid + 1;
        while(i <= mid && j <= e)
        {
            if((long)nums[i] >(long)2*nums[j])
            {
                count += mid - i + 1;
                j++;
            }
            else
                i++;
        }
        
        sort(nums.begin() + s, nums.begin() + e + 1);
        return;
    }
    void inversion_Count(vector<int>&arr, int s, int e){
        if(s >= e){
            return;
        }
        int mid = (s + e)/2;
        inversion_Count(arr, s, mid);
        inversion_Count(arr, mid + 1, e);
        merge(arr, s, mid, e);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        count = 0;
        inversion_Count(nums, 0, n-1);
        return count;
    }
};
