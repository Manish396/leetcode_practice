class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = 0;
        int n = nums.size();
        int curr = 1, res = INT_MIN;
       
        for (auto i: nums) {
            curr = curr * i;
            res = max(curr, res);
            if(curr == 0) {
                curr = 1;
            }
        }
        curr = 1;
        for (int i = n - 1; i >= 0; i--) {
           curr = curr * nums[i];
           res = max(curr, res);
           if(curr == 0) {
               curr = 1;
           }      
        }
        return res;
    }
};
