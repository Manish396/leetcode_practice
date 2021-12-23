class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){
            return n;
        }
        int start = 0, end = 1;
        while(end < n){
            if(nums[end] > nums[start]){
                start++;
                swap(nums[start], nums[end]);
            }
            end++;
        }
        return start+1;
    }
};
