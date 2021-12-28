class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        for(int i = 0; i < 31 and (1 << i) <= num; i++){
            if(!(num & (1 << i))){
                ans += (1 << i);
            }
        }
        return ans;
    }
};
