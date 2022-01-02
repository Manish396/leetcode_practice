class Solution {
public:
    int longestSubstr(string s, int k, int start, int end){
        int left, right;
        int cnt[26] = {0};
        for(int i=start; i<end; i++){
            cnt[s[i] - 'a']++;
        }
        for(int i = start; i < end; i++){
            if(cnt[s[i]-'a'] < k){
                left = longestSubstr(s, k, start, i);
                right = longestSubstr(s, k, i+1, end);
                return max(left, right);
            }
        }
        return end - start;
    }
    int longestSubstring(string s, int k) {
        int n = s.length();
        if(k > n){
            return 0;
        }
        return longestSubstr(s, k, 0, n);
    }
};
