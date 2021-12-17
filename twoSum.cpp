class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int, int>mp1;
        for(int i = 0; i < n; i++){
            mp1[nums[i]] = i;
        }
        for(int i = 0; i < n; i++){
            int rest = target - nums[i];
            if(mp1.find(rest)!=mp1.end() and mp1[rest]!=i){
                ans.push_back(min(i, mp1[rest]));
                ans.push_back(max(i, mp1[rest]));
                return ans;
            }
        }
        return ans;
    }
};
