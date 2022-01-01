class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        map<char, int>freq;
        for(auto c: s){
            freq[c]++;
        }
        int ans = 0, one = 0;
        for(auto it: freq){
            if(it.second%2 == 0){
                ans += it.second;
            }
            else{
                if(it.second > 0){
                    one++;
                }
                ans += it.second - 1;
            }
        }
        if(one){
            ans += 1;
        }
        return ans;
    }
};
