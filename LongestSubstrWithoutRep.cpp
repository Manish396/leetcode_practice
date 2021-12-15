class Solution {
public:
    int max(int a, int b){
        return (a>b) ? a:b;
    }
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        string temp = "";
        int maxLen = 0;
        for(int i=0; i<n; i++){
            char ch = s[i];
            size_t found = temp.find(ch);
            if(found != string::npos){
                if(temp.length() > maxLen){
                    maxLen = temp.length();
                }
                temp.erase(0, found+1);
                temp+=ch;
            }
            else{
                temp+=ch;
            }
        }
        if(temp.length() > maxLen){
            maxLen = temp.length();
        }
        return maxLen;
    }
};
