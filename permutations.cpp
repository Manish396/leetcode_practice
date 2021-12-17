class Solution {
public:
    void all_permutations(vector<int>&nums,int s, int n, vector<vector<int>>&res){
        if(s == n-1){
            res.push_back(nums);
            return;
        }
        for(int i = s; i<n; i++){
            swap(nums[s], nums[i]);
            all_permutations(nums, s+1, n, res);
            swap(nums[s], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>res;
        all_permutations(nums, 0, n, res);
        return res;
    }
};
