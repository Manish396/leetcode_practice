class Solution {
public:
    int lengthLongestPath(string input) {
        vector<string>path;
        string str = "";
        for(int i = 0; i <= input.size(); ++i)
        {
            if(i == input.size()||input[i]=='\n'){
                path.push_back(str);
                str="";
            } 
            else{
                str += input[i];
            }
        }
        int ans = 0;
        map<int, int>mp;
        for(string &str: path)
        {
            int i;
            for(i = 0; i < str.size(); i++){
                if(str[i] == '\t'){
                    continue;
                }
                else{
                    break;
                }
            }
            mp[i] = mp[i-1] + str.size() - i;
            if(str.find('.')!= string::npos)
                ans = max(ans, mp[i]+i);
        }
        return ans;
    }
};
