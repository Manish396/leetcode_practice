class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char>mp;
        vector<int>arr(128, 0);
        for(int i = 0; i < s.length(); i++){
            if(!mp[s[i]]){
                if(arr[t[i]] == 0){
                    mp[s[i]] = t[i];
                    arr[t[i]] = 1;
                }
                else{
                    return false;
                }
            }
            else{
                if(mp[s[i]] != t[i]){
                    return false;
                } 
            }
        }
        return true;
    }
};
