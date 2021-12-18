class Solution {
public:
    string lastSubstring(string s) {
        string temp = s;
        char ch = 'a';
        int ans = 0, n = s.length();
        for(int i = 0; i < n; i++){
            if(ch < s[i]){
                ch = s[i];
                ans = i;
            }
        }
        for(int i = ans + 1; i<s.length(); i++)
        {
            if(s[i] == ch)
            {
                int  j = 1;
                while(ans+j < i && s[i+j]==s[ans+j])
                {
                    j++;
                }
                if(s[i+j] > s[ans+j])
                {
                    ans=i;
                }
                i = i+j-1;
            }
        }
        return s.substr(ans);
    }
};
