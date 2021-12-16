class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 1){
            return 1;
        }
        int ans = 0;
        for(int i = 1; i*i <= n; i++){
            if(i * i <= n){
                ans++;
            }
        }
        return ans;
    }
};
