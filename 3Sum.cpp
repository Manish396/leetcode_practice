class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> result;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i < n-2; i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int temp = nums[i];
                temp+=nums[j];
                temp+=nums[k];
                if(temp==0){
                    result.insert({nums[i], nums[j], nums[k]});
                    j++, k--;
                }
                else if(temp>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        vector<vector<int>>vec(result.begin(),result.end());
        return vec;
    }
};
