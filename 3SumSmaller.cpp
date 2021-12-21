class Solution {
public:
    int threeSumSmaller(vector<int> &nums, int target) {
        int ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            int temp = nums[i];
            int j = i + 1, k = n - 1;
            while(j < k){
                temp += nums[j] + nums[k];
                if(temp < target){
                    ans+= k - j;
                    j++;
                }else{
                    k--;
                }
                temp = nums[i];
            }
        }
        return ans;
    }
};
