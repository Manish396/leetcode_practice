class Solution {
public:
    vector<string> res;
    unordered_map<string,int> mp;
    int getMinInvalid(string s)
    {
        stack<char> stck;
        int i = 0;
        while(i < s.size())
        {
            if(s[i] == '(')
                stck.push('(');
            else if(s[i] == ')')
            {
                if(stck.size() > 0 && stck.top() == '(')
                    stck.pop();
                else
                    stck.push(')');
            }
            i++;
        }
        return stck.size();
    }
    void solve(string s,int minInv)
    {
        if(mp[s] != 0)
            return;
        else
            mp[s]++;
        
        if(minInv == 0)
        {
            if(!getMinInvalid(s))
                res.push_back(s);
            return;
        }
        
        for(int i=0; i<s.size(); i++)
        {
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            solve(left+right, minInv-1);
        }
        return;
    }
    vector<string> removeInvalidParentheses(string s) 
    {
        solve(s, getMinInvalid(s));
        return res;
    }
};
