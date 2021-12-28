class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        int setSize = pow(2, n);
        set<vector<int>>res;
        for(int i = 0; i < setSize; i++){
            vector<int>temp;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    temp.push_back(nums[j]);
                }
            }
            sort(temp.begin(), temp.end());
            res.insert(temp);
        }
        vector<vector<int>>result(res.begin(), res.end());
        return result;
    }
};
