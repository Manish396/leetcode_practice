class Solution {
public:
    int maximumGap(vector<int>& nums) {
        set<int>st(nums.begin(), nums.end());
        int prev = *st.begin();
        int ans = INT_MIN;
        for(auto it: st){
            if(it- prev > ans){
                ans = it - prev;
            }
            prev = it;
        }
        if(ans == INT_MIN) ans = 0;
        return ans;
    }
};
