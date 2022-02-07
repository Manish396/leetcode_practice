class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int start = n-2;
        while(start >= 0){
            if(nums[start] < nums[start + 1]){
                break;
            }
            start--;
        }
        if(start < 0){
            reverse(nums.begin(), nums.end());
        }
        else{
            int k = n-1;
            while(k > start){
                if(nums[k] > nums[start]){
                    break;
                }
                k--;
            }
            swap(nums[start], nums[k]);
            reverse(nums.begin() + start + 1, nums.end());
        }
    }
};
