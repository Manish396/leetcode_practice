class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>mv;
        for(int i = 0; i < nums.size(); i++){
            if(mv[nums[i]]){
                if(abs(i + 1 - mv[nums[i]]) <= k){
                    return true;
                }
            }
            mv[nums[i]] = i+1;
        }
        return false;
    }
};
