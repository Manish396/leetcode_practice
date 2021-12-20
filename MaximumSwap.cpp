class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        int idx = 0;
        vector<char>vec(s.length(), '0');
        vec[n-1] = s[n-1];
        for(int i = s.length()-2; i >=0; i--){
            vec[i] = max(s[i], vec[i+1]);
        }
        for(int i = 0; i < n; i++){
            if(s[i] != vec[i]){
                int found = i;
                for(int j = i+1; j < n; j++){
                    if(s[j] == vec[i]){
                        found = j;
                    }
                }
                swap(s[i], s[found]);
                break;
            }
        };
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += s[i] - '0';
            if(i!=n-1){
                ans*=10;
            }
        }
        return ans;
    }
};
