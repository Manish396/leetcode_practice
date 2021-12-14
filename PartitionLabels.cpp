class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.length();
        vector<int>ans;
        vector<int>ch(27, 0);
        for(int i = 0; i < n; i++){
            ch[s[i] - 'a'] = i;
            
        }
        int start = 0;
        int curr = ch[s[0] - 'a'];
        for(int i = 1; i < n; i++){
            if(i <= curr){
                if(ch[s[i] - 'a'] > curr){
                    curr = ch[s[i] - 'a'];
                }
            }
            else{
                ans.push_back(curr - start + 1);
                curr = ch[s[i]-'a'];
                start = i;
            }
            // cout << curr << " ";
        }
        ans.push_back(curr - start + 1);
        return ans;
    }
};
