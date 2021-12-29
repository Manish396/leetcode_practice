class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        vector<int> lps(2*n+1,0);
        string str = s, temp = s;
        reverse(str.begin(),str.end());
        s += "$" + str;
        int i = 0 , j = 1;
        while(j < s.length())
        {
            if(s[i] == s[j])
            {
                lps[j] = i + 1;
                i++, j++;
            }
            else 
            {
                if(i != 0)
                    i = lps[i-1];
                else 
                {
                    lps[j] = 0;
                    j++;
                }
            }
        }
        int ans = lps.back();
        string sub = str.substr(0,n-ans);
        temp = sub + temp;
        return temp;
    }
};
