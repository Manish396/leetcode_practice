class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit[n];
        int max_price = prices[n-1];
        profit[n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            max_price = max(max_price, prices[i]);
            profit[i] = max(max_price - prices[i], profit[i+1]);
        }
        int min_price = prices[0];
        for(int i = 1; i < n; i++){
            min_price = min(min_price, prices[i]);
            profit[i] = max(profit[i-1], profit[i]+prices[i]-min_price);
        }
        return profit[n-1];
    }
};
