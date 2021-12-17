class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string a = strs[0];
        int n = strs.size();
        int ans = INT_MAX;
        for(int i = 1; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < strs[i].length() and j < a.length(); j++){
                if(strs[i][j] == a[j]){
                    cnt++;
                }
                else{
                    break;
                }
            }
            ans = min(ans, cnt);
        }
        return a.substr(0, ans);
    }
};
