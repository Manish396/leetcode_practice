class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int>factorial;
        factorial.push_back(1);
        string num = "";
        k--;
        for(int i = 1; i <= n; i++){
            factorial.push_back(i * factorial.back());
            num += char('0' + i);
        }
        for(int i = 1; i <= n; i++){
            int idx = k/factorial[n - i];
            k = k % factorial[n-i];
            ans += num[idx];
            num.erase(idx, 1);
        }
        return ans;
    }
};
