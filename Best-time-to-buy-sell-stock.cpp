class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxi = prices[0];
        int ans = maxi - mini;
        int n = prices.size();
        for(int i = 1; i < n; i++){
            if(prices[i] > mini){
                maxi = prices[i];
                ans = max(ans, maxi - mini);
            }
            else{
                mini = prices[i];
                maxi = prices[i];
            }
        }
        return ans;
    }
};
