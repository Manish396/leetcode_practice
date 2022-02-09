class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int>dif(n, 0);
        for(int i = 1; i < n; i++){
            dif[i-1] = nums[i] - nums[i-1];
        }
        int ans = 0;
        int temp = 0;
        bool neg = true, pos = false;
        for(int i = 0; i < n-1; i++){
            if(dif[i] > 0 and neg){
                temp++;
                neg = false;
                pos = true;
            }
            else if(dif[i] < 0 and pos){
                temp++;
                pos = false;
                neg = true;
            }
        }
        ans = max(ans, temp);
        temp = 0;
        neg = false, pos = true;
        for(int i = 0; i < n-1; i++){
            if(dif[i] > 0 and neg){
                temp++;
                neg = false;
                pos = true;
            }
            else if(dif[i] < 0 and pos){
                temp++;
                pos = false;
                neg = true;
            }
        }
        ans = max(ans, temp);
        return ans+1;
    }
};
