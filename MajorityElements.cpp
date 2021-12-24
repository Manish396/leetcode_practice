class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj = nums[0], cnt = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == maj){
                cnt++;
            }
            else{
                cnt--;
            }
            if(cnt < 0){
                maj = nums[i];
                cnt = 1;
            }
        }
        if(cnt > 0){
            int cc = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] == maj) cc++;
            }
            if(cc > n/2){
                return maj;
            }
        }
        return -1;
    }
};
