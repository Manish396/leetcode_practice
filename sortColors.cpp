class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int counter = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                swap(nums[i], nums[counter++]);
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                swap(nums[i], nums[counter++]);
            }
        }
    }
};
