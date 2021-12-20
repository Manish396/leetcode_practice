class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            int l = i, r  = i;
            while(l >=0 and r < n and s[l] == s[r]){
                res += 1;
                l--, r++;
            }
            l = i;
            r = i + 1;
            while(l >=0 and r < n and s[l] == s[r]){
                res += 1;
                l--, r++;
            }
        }
        return res;
    }
};
