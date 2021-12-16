class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 0, sell = 0; int prof = 0;
        for(int i = 1; i < n; i++){
            if(prices[i] > prices[buy]){
                prof += prices[i] - prices[buy];
                buy = i;
            }
            if(prices[i] < prices[buy]){
                buy = i;
            }
        }
        return prof;
    }
};
