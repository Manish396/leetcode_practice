class Solution {
public:
    set<vector<int>>result;
    void backtrack(vector<int>&nums, int index, int r){
        if(index == r){
            result.insert(nums);
        }
        for(int i = index; i <= r; i++){
            swap(nums[i], nums[index]);
            backtrack(nums, index + 1, r);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        int n = nums.size();
        backtrack(nums, 0, n-1);
        vector<vector<int>>res;
        for(auto it: result){
            res.push_back(it);
        }
        return res;
    }
};
