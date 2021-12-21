class Solution {
public:
    bool isValid(vector<int>& weights, int n, int days, int box){
        int s = 1, sum = 0;
        for(int i = 0; i < n; i++){
            sum += weights[i];
            if(sum > box){
                s++;
                sum = weights[i];
            }
        }
        return (s > days) ? false:true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long n = weights.size(), sum = 0, maxi = 0, ans = 0;
        for(int i = 0; i < n; i++){
            sum += weights[i];
            maxi = max(maxi, (long long)weights[i]);
        }
        while(maxi <= sum){
            long long mid = (maxi + sum)/2;
            if(isValid(weights, n, days, mid)){
                ans = mid;
                sum = mid - 1;
            }
            else{
                maxi = mid + 1;
            }
        }
        return ans;
    }
};
