class Solution {
public:
    vector<vector<string>>ans;
    bool isPalindrome(string s){
        for(int i = 0; i < s.length()/2; i++){
            if(s[i] != s[s.length() - i -1]){
                return false;
            }
        }
        return true;
    }
    void solve(string s, vector<string>v){
        if(s.size() == 0){
            ans.push_back(v);
            return;
        }
        for(int i = 0; i < s.length(); i++){
            string temp = s.substr(0, i+1);
            string rest = s.substr(i+1);
            if(isPalindrome(temp)){
                v.push_back(temp);
                solve(rest, v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>v;
        solve(s, v);
        return ans;
    }
};
